// Solving 1st order DE using Runge-Kutta method
// mahmoodakhlak at gmail dot com

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double func(double x, double y)
{
    return y + x*y*y/10.0;
}

double RK4(double f(double, double), double x, double y, double h)
{
    double k1, k2, k3, k4;

    k1 = h * f(x, y);
    k2 = h * f(x + h/2.0, y + k1/2.0);
    k3 = h * f(x + h/2.0, y + k2/2.0);
    k4 = h * f(x + h, y + k3);

    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}


int main()
{
    // open a new file to save the data
    ofstream fout("Rk4.dat");

    // initial value of y
    double y = 2;

    // x increment
    double h = 0.1;

    for(double x=0; x<=1; x = x + h)
    {
        // print the current values of x and y
        cout << x << "  " << y << endl;
        fout << x << "  " << y << endl;

        // get the new y, new x is got from x+=h
        y = RK4(func, x, y, h);
    }

    // close the file
    fout.close();

    return 0;
}
