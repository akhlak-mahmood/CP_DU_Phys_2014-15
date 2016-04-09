// Solving 2nd order DE using Runge-Kutta method
// mahmoodakhlak at gmail dot com

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double xfunc(double t, double x, double y)
{
    return 5*x - 2*y;
}

double yfunc(double t, double x, double y)
{
    return 3*x;
}

void RK4o2(double f(double, double, double),
               double g(double, double, double),
               double t,
               double h,
               double &x,
               double &y)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h * f(t, x, y);
    m1 = h * g(t, x, y);

    k2 = h * f(t + h/2.0, x + k1/2.0, y + m1/2.0);
    m2 = h * g(t + h/2.0, x + k1/2.0, y + m1/2.0);

    k3 = h * f(t + h/2.0, x + k2/2.0, y + m2/2.0);
    m3 = h * g(t + h/2.0, x + k2/2.0, y + m2/2.0);

    k4 = h * f(t+h, x + k3, y + m3);
    m4 = h * g(t+h, x + k3, y + m3);

    x = x + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    y = y + (m1 + 2 * m2 + 2 * m3 + m4) / 6.0;
}

int main()
{
    ofstream fout("rk2o.dat");

    double x = 1;
    double y = 2;

    double h = 0.1;

    for(double t=0; t<=1; t += h)
    {
        cout << t << "  " << x << "  " << y << endl;
        fout << t << "  " << x << "  " << y << endl;

        RK4o2(xfunc, yfunc, t, h, x, y);
    }

    fout.close();

    return 0;
}
