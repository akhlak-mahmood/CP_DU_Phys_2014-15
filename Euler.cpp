// Solving 1st order DE using Euler and Improved Euler method
// mahmoodakhlak at gmail dot com

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

// RHS of our 1st order differential equation
double func(double x, double y)
{
    return y + x*y*y/10.0;
}

double euler(double f(double, double), double x, double y, double h)
{
    return y + h * f(x, y);
}

double improved_euler(double f(double, double), double x, double y, double h)
{
    double yp;
    yp = y + h * f(x, y);
    return y + h / 2.0 * (f(x, y) + f(x + h, yp));
}

int main()
{
    // to plot in GNUPlot
    ofstream fout("Euler.txt");
    double h = 0.1;
    // initial value of y
    double y = 2;

    cout.precision(20);

    // we start from the initial value of x
    for(double x=0; x<=1; x += h)
    {
        // print the current values of x and y first
        cout << "y(" << x << ") = " << y << endl;
        fout << x << "  " << y << endl;

        // then, get the new value of y
        // new x value is got from loop increment x+=h
        y = improved_euler(func, x, y, h);
    }

    // close the file
    fout.close();

    return 0;
}
