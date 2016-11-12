#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double U(double t)
{
    return 0;
}

double V(double t)
{
    return - 4 * M_PI * M_PI;
}


double F(double t, double y)
{
    return U(t) + V(t) * y;
}

double getY1(double h, double t, double y, double yd)
{
    double u1 = U(t + h);
    double u2 = U(t + 2*h);
    double v1 = V(t + h);
    double v2 = V(t + 2*h);
    double f0 = F(t, y);
    double h4 = h*h*h*h;

    double y1;

    y1 = y * (1 - v2*h*h/24.0) + h * yd * (1 - v2 * h*h/12.0);
    y1 += h*h * (7*f0 + 6*u1 - u2)/24.0 - h4 * v2/36.0 * (f0 + 2*u1);
    y1 /= (1 - v1*h*h/4.0 + v1*v2*h4/18.0);

    return y1;
}

double getNewY(double h, double t, double y, double yOld)
{
    double ynew;
    ynew = 2*y - yOld + h*h/12 * (U(t+h) + 10*F(t, y) + F(t-h, yOld));
    ynew /= (1 - V(t+h) *h*h/12);
    return ynew;

}

double yf(double t, double y, double v)
{
    return v;
}

double vf(double t, double y, double v)
{
    return - 4 * M_PI * M_PI * y;
}

void RK4(double h, double t, double &y, double &v)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h * yf(t, y, v);
    m1 = h * vf(t, y ,v);

    k2 = h * yf(t+h/2, y+k1/2, v+m1/2);
    m2 = h * vf(t+h/2, y+k1/2, v+m1/2);

    k3 = h * yf(t+h/2, y+k2/2, v+m2/2);
    m3 = h * vf(t+h/2, y+k2/2, v+m2/2);

    k4 = h * yf(t+h, y+k3, v+m3);
    m4 = h * vf(t+h, y+k3, v+m3);

    y = y + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    v = v + (m1 + 2*m2 + 2*m3 + m4)/6.0;
}


int main()
{
    double h = 0.1;
    double ti = 0;
    double y = 1;
    double v = 0;
    double yold, ynew;

    ofstream nout("numerov.txt");

    for(double t=ti; t <=10; t=t+h) {
        cout << t << "  " << y << endl;
        nout << t << "  " << y << endl;

        if(t >= ti+h) {
            ynew = getNewY(h, t, y, yold);
        }
        else {
            ynew = getY1(h, t, y, v);
        }
        yold = y;
        y = ynew;
    }

    nout.close();

    y = 1;
    v = 0;
    ofstream rout("rk4.txt");

    for(double t=ti; t<=10; t+=h) {
        cout << t << "  " << y << "  " << v << endl;
        rout << t << "  " << y << "  " << v << endl;

        RK4(h, t, y, v);
    }
    rout.close();


    /**
    Now on the GNUPLOT:
        > set terminal postscript
        > set output "mygraph.ps"
        > plot "numerov.txt" w l, "rk4.txt" w l
    */
    return 0;
}
