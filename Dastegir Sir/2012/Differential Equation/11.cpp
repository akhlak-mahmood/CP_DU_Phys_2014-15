#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double k = 1.0;
double a = 0.05;

double f(double t, double x, double v)
{
    return v;
}

double g(double t, double x, double v)
{
    return -k * x - a * x*x*x;
}


double RK4(double t, double &x, double &v, double h)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h * f(t, x, v);
    m1 = h * g(t, x, v);

    k2 = h * f(t + h/2, x + k1/2, v + m1/2);
    m2 = h * g(t + h/2, x + k1/2, v + m1/2);

    k3 = h * f(t + h/2, x + k2/2, v + m2/2);
    m3 = h * g(t + h/2, x + k2/2, v + m2/2);

    k4 = h * f(t + h, x + k3, v + m3);
    m4 = h * g(t + h, x + k3, v + m3);

    x = x + (k1 + 2*k2 + 2*k3 + k4)/6;
    v = v + (m1 + 2*m2 + 2*m3 + m4)/6;
}


int main()
{
    ofstream fout("11.txt");

    double h = 0.1;
    double x = 0.1;
    double v = 0;

    for(double t=0; t<=50; t+=h) {
        cout << t << "  " << x << "  " << v << endl;
        fout << t << "  " << x << "  " << v << endl;

        RK4(t, x, v, h);
    }

    fout.close();

    return 0;
}
