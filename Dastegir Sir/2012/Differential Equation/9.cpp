#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double A = 0.9;
double B = 0.65;

double f(double t, double x, double y)
{
    return A + x*x * y - (B + 1) * x;
}

double g(double t, double x, double y)
{
    return B * x - x*x * y;
}


void Euler(double t, double &x, double &y, double h)
{
    double x0 = x;
    double y0 = y;

    x = x + h * f(t, x0, y0);
    y = y + h * g(t, x0, y0);
}


int main()
{
    ofstream fout("9.txt");

    double h=0.1;
    double x=0.5;
    double y=0.8;

    for(double t=0.0; t<=10; t+=h) {
        cout << t << "  " << x << "  " << y << endl;
        fout << t << "  " << x << "  " << y << endl;

        Euler(t, x, y, h);
    }

    fout.close();

    return 0;

    /// GNUPLOT:
    /// set terminal postscript
    /// set output "9.ps"
    /// plot "9.txt" u 1:2 w l, "9.txt" u 1:3 w l
}
