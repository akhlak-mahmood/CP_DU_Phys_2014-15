#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double k = 0.995;

double f(double t, double y, double v)
{
    return v;
}

double g(double t, double y, double v)
{
    return - k*k * y;
}

void RK4(double h, double t, double &y, double &v)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h * f(t, y, v);
    m1 = h * g(t, y, v);

    k2 = h * f(t+h/2, y+k1/2, v+m1/2);
    m2 = h * g(t+h/2, y+k1/2, v+m1/2);

    k3 = h * f(t+h/2, y+k2/2, v+m2/2);
    m3 = h * g(t+h/2, y+k2/2, v+m2/2);

    k4 = h * f(t+h, y+k3, v+m3);
    m4 = h * g(t+h, y+k3, v+m3);

    y += (k1 + 2*k2 + 2*k3 + k4)/6;
    v += (m1 + 2*m2 + 2*m3 + m4)/6;
}


double U(double t)
{
    return 0;
}

double V(double t)
{
    return - k*k;
}

double F(double t, double y)
{
    return U(t) + V(t) * y;
}

double getY1(double h, double t, double y, double yd)
{
    double u1 = U(t+h);
    double u2 = U(t+2*h);
    double v1 = V(t+h);
    double v2 = V(t+2*h);
    double f0 = F(t, y);
    double h4 = h*h*h*h;

    double y1;
    y1 = y * (1 - v2*h*h/24) + h * yd * (1 - v2 *h*h/12);
    y1 += h*h/24 * (7*f0 + 6*u1 - u2) - h4*v2/36 * (f0 + 2*u1);
    y1 /= (1 - v1*h*h/4 + v1*v2*h4/18);
    return y1;
}

double getNewY(double h, double t, double y, double yold)
{
    double ynew;
    ynew = 2*y - yold + h*h/12 * (U(t+h) + 10*F(t, y) + F(t-h, yold));
    ynew /= (1 - V(t+h) * h*h/12);
    return ynew;
}

int main()
{
    double h = 0.01;
    double ti = 0;
    double y = 0;
    double yd = 1;
    double yold, ynew;

    ofstream nout("schnum.txt");

    for(double t=ti; t<=2*M_PI; t+=h) {
        cout << t << "  " << y << endl;
        nout << t << "  " << y << endl;

        if(t>ti+h) {
            ynew = getNewY(h, t, y, yold);
        }
        else {
            ynew = getY1(h, t, y, yd);
        }
        yold = y;
        y = ynew;
    }
    nout.close();

    double x = 0;
    double v = 1;

    ofstream rout("schrk4.txt");

    for(double t=ti; t<=2*M_PI; t+=h) {
        rout << t << "  " << x << endl;
        cout << t << "  " << x << endl;
        RK4(h, t, x, v);
    }
    rout.close();

    /**
    Now on the GNUPLOT:
        > set terminal postscript
        > set output "mygraph.ps"
        > plot "schnum.txt" w l, "schrk4.txt" w l
    */

    return 0;
}
