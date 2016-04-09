#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return cos(x) - x*x;
}

// this function gives me the value of alpha
// by solving the corresponding equation
double getroot()
{
    /// we shall be using the Bisection Method here to find the root
    double x;

    /// As its a transcendental equation, we are checking for
    /// 0 to 2*Pi for the positive root
    double a = 0;
    double b = 2*M_PI;

    double epsilon = 0.001;
    double delta = 0.001;
    int nIter = 50;

    if(f(a) == 0) return a;
    if(f(b) == 0) return b;

    if(f(a) * f(b) > 0)
    {
        // Just in case!
        cout << "Error! Invalid [a, b] range." << endl;
        exit(1);
    }
    else
    {
        for(int i=1; i<=nIter; i++)
        {
            x = (a+b)/2.0;

            if(f(x) == 0) return x;

            if(abs(a-b) < delta) return x;

            if(abs(f(x)) < epsilon) return x;

            if(f(x) * f(b) < 0) a = x;
            else b = x;
        }

        return x;
    }
}


double I(double x)
{
    // yeah, this is gonna work
    return sqrt(f(x));
}

double getArea()
{
    // We are using the Simpsons 1/3 to evaluate the integral
    double xi = 0.0;
    double xf = getroot();
    int nIter = 50;

    double h = (xf - xi) / nIter;
    double sum = 0.0;

    for(int i=1; i<=nIter-1; i+=2)
    {
        sum += 4 * I(xi + i*h);
    }

    for(int i=2; i<=nIter-2; i+=2)
    {
        sum += 2 * I(xi + i*h);
    }

    return 4 * (h/3.0) * (I(xi) + sum + I(xf));
}

int main()
{
    cout << "The positive root is " << getroot() << endl;
    cout << "The area is " << getArea() << endl;

    return 0;
}
