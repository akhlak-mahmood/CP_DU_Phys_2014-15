#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double simpson(double f(double), double xi, double xf, int N)
{
    double h = (xf - xi) / (double) N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i+=2)
    {
        sum += 4.0 * f(xi + i * h);
    }

    for(int i=2; i<=N-2; i+=2)
    {
        sum += 2.0 * f(xi + i * h);
    }

    return (h/3.0) * (f(xi) + sum + f(xf));
}

double I1(double x)
{
    return 1.0/(1+sin(x));
}

double I2(double x)
{
    return 1.0/sqrt(x*x - 4);
}

double I3(double x)
{
    return x*x*x * exp(x);
}

double I4(double x)
{
    return (2.0 - 2.0*x + sin(x-1) + x*x) / (1.0 + (x-1)*(x-1));
}

int main()
{
    int iteration_count = 20;

    cout << "I1 = " << simpson(I1, 0, M_PI_2, iteration_count) << endl;
    cout << "I2 = " << simpson(I2, 3, 5, iteration_count) << endl;
    cout << "I3 = " << simpson(I3, -2, 2, iteration_count) << endl;
    cout << "I4 = " << simpson(I4, 0.5, 1.5, iteration_count) << endl;

    return 0;
}
