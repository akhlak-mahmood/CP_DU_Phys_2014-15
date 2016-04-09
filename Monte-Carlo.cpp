#include <iostream>
#include <cstdlib>
#include <cmath>

//#include <random>
#include <ctime>

using namespace std;

double randomBetween(int a, int b)
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

double func1(double x)
{
    // exact ans = 2 for 0 to Pi
    return sin(x);
}

int main()
{
    srand(time(NULL));

    cout << MonteCarlo1D(func1, 0, M_PI, 10000) << endl;

    return 0;
}
