#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double F(double t)
{
    return 4.0 + 0.2*sin(t);
}

double G(double t)
{
    return cos(t);
}


double getY1(double h, double t0, double y0, double yp)
{
    double g0 = G(t0);
    double g1 = G(t0+h);
    double g2 = G(t0+2*h);

    double f0 = F(t0);
    double f1 = F(t0+h);
    double f2 = F(t0+2*h);

    double h4 = h*h*h*h;

    double y1;
    y1 = y0 * (1 + f2 * h*h/24) + h*yp*(1+f2*h*h/24);
    y1 += (h*h/24)*(7*g0 - 7*f0*y0 + 6*g1 - g2) + h4*f2/36 * (g0 - f0*y0 +2*g1);
    y1 /= (1 + f1*h*h/4 + f1*f2*h4/18);
    return y1;
}


double getYn(double h, double t, double y, double yo)
{
    double yn;
    yn = (2 - 5/6 *h*h * F(t))*y - (1+h*h/12 * F(t-h))*yo - (h*h/12) * (G(t-h) * 10*G(t) - G(t-h));
    yn /= (1+h*h/12*F(t+h));
    return yn;
}

int main()
{
    ofstream fout("4.dat");
    double h = 0.01;
    double ti = 0;
    double yi = 0.5;
    double yip = 0.5;

    double y = yi;
    double yn, yo;

    for(double t=ti; t<=20; t+=h) {
        cout << t << "  " << y << endl;
        fout << t << "  " << y << endl;

        if(t==ti) yn = getY1(h, ti, yi, yip);
        else yn = getYn(h, t, y, yo);

        yo = y;
        y = yn;
    }

    return 0;
}
