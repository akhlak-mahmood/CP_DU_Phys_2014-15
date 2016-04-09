#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double h = 0.01;

double func(double x)
{
    return 3*x*x + 2*x;
}

double fprime(double x)
{
    return 6*x + 2;
}

double fpprime(double x)
{
    return 6;
}

double backwardD(double f(double), double x)
{
    return (3*f(x)-4*f(x-h)+f(x-2*h))/(2*h);
}

double backwardDD(double f(double), double x)
{
    return (f(x) - 2*f(x-h) + f(x-2*h))/(h*h);
}

double centralD(double f(double), double x)
{
    return (- f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h))/(12 * h);
}

double centralDD(double f(double), double x)
{
    return (f(x+h) - 2*f(x) + f(x-h))/(h*h);
}

double forwardD(double f(double), double x)
{
    return (-f(x+2*h) + 4*f(x+h) - 3*f(x))/(2*h);
}

double forwardDD(double f(double), double x)
{
    return (f(x+2*h) - 2*f(x+h) + f(x))/(h*h);
}

int main()
{
    double x = 3;
    cout << fprime(x) << endl;
    cout << backwardD(func, x) << endl;
    cout << centralD(func, x) << endl;
    cout << forwardD(func, x) << endl;

    cout << fpprime(x) << endl;
    cout << backwardDD(func, x) << endl;
    cout << centralDD(func, x) << endl;
    cout << forwardDD(func, x) << endl;

    return 0;
}
