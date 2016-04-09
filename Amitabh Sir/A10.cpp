#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double A = 0.9;
double B = 0.65;

double f(double t, double x, double y)
{
    return A + x*x*y - (B+1) * x;
}

double g(double t, double x, double y)
{
    return B*x - x*x*y;
}

void RK2nd(double t, double &x, double &y, double h)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h*f(t, x, y);
    m1 = h*g(t, x, y);

    k2 = h*f(t+h/2, x+k1/2, y+m1/2);
    m2 = h*g(t+h/2, x+k1/2, y+m1/2);

    k3 = h*f(t+h/2, x+k2/2, y+m2/2);
    m3 = h*g(t+h/2, x+k2/2, y+m2/2);

    k4 = h*f(t+h, x+k3, y+m3);
    m4 = h*g(t+h, x+k3, y+m3);

    x = x + (k1 + 2*k2 + 2*k3 + k4)/6;
    y = y + (m1 + 2*m2 + 2*m3 + m4)/6;
}

int main()
{
    double h = 0.1;
    double x = 0.5;
    double y = 0.8;

    ofstream fout("A10.txt");

    for(double t=0; t<=10; t+=h)
    {
        cout << t << "  " << x << "  " << y << endl;
        fout << t << "  " << x << "  " << y << endl;

        RK2nd(t, x, y, h);
    }

    fout.close();

    return 0;
}
