#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double simpson13(double f(double), double a, double b, int N)
{
    if(N<2 || N%2 == 1) exit(1);

    double h = (b - a) / (double) N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i+=2) {
        sum += 4 * f(a + i*h);
    }

    for(int i=2; i<=N-2; i+=2) {
        sum += 2 * f(a + i*h);
    }

    return h / 3.0 * (f(a) + sum + f(b));
}


double I2(double x)
{
    return 1.0 / sqrt(x*x - 4);
}

double I3(double x)
{
    return x*x*x * exp(x);
}

double I4(double x)
{
    return (2 - 2*x + sin(x-1) + x*x) / (1 + (x-1)*(x-1));
}


int main()
{
    cout << "I2 = " << simpson13(I2, 3, 5, 50) << endl;
    cout << "I3 = " << simpson13(I3, -2, 2, 50) << endl;
    cout << "I4 = " << simpson13(I4, 0.5, 1.5, 50) << endl;

    return 0;
}
