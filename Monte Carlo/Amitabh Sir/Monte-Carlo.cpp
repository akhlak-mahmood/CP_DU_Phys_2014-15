#include <iostream>
#include <cstdlib>
#include <cmath>

//#include <random>
#include <ctime>

using namespace std;

double randomBetween(double a, double b)
{
    return a + (b-a) * (double(rand())/double(RAND_MAX));
}

double MonteCarlo1D(double f(double), double a, double b, int n)
{
    double sum = 0.0;
    for(int i=0; i<n; i++) {
        sum += f(randomBetween(a, b));
    }

    return (b - a) * sum / double(n);
}

double MonteCarlo2D(double f(double, double),
                    double a,
                    double b,
                    double c,
                    double d, int n)
{
    double sum = 0.0;
    for(int i=0; i<n; i++) {
        sum += f(randomBetween(a, b), randomBetween(c, d));
    }
    return (b - a) * (d - c) * sum / (double) n;
}

double func1(double x)
{
    // exact ans = 2 for 0 to Pi
    return sin(x);
}

double circle(double x, double y)
{
    return x*x + y*y;
}

int main()
{
    srand(time(NULL));

    cout << MonteCarlo1D(func1, 0, M_PI, 10000) << endl;
    cout << MonteCarlo2D(circle, 0, 1, 0, 1, 50*1000) << endl;

    return 0;
}
