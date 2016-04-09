// Solving 2nd order DE using Euler method
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

void euler2o(double f(double, double, double),
               double g(double, double, double),
               double t,
               double h,
               double &x,
               double &y)
{
   x = x + h * f(t, x, y);
   y = y + h * g(t, x, y);
}

int main()
{
    ofstream fout("euler2o.dat");

    double x = 1;
    double y = 2;

    double h = 0.1;

    for(double t=0; t<=1; t += h)
    {
        cout << t << "  " << x << "  " << y << endl;
        fout << t << "  " << x << "  " << y << endl;

        euler2o(xfunc, yfunc, t, h, x, y);
    }

    fout.close();

    return 0;
}
