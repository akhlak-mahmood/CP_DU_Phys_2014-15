#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double epsilon = 0.001;
double delta = 0.001;

double func(double x)
{
    return (-1.0 / tan(x)) - (sqrt(10.498597 - x*x) / x);
}

double bisect(double f(double), double a, double b, int N)
{
    double x;

    if(f(a) == 0) { return a; }
    if(f(b) == 0) return b;

    if(f(a)*f(b) > 0) exit(2);

    for(int i=0; i<N; i++)
    {
        x = (a+b) / 2.0;

        if(f(x) == 0) return x;

        if(abs(b-a) < epsilon) return x;

        if(abs(f(x)) < delta) return x;

        if(f(x)*f(b) < 0) a = x;
        else b = x;
    }

    return x;
}


int main()
{
    ofstream fout("5.dat");
    for(double x=-2; x <= 2; x+=0.1)
    {
        fout << x << "  " << -1.0/tan(x) << "  " << sqrt(10.498597 - x*x)/x << endl;
    }

    fout.close();

    cout << "Root = " << bisect(func, 1.5, 2.5, 50) << endl;
    cout << "Root = " << bisect(func, -1.5, -3, 50) << endl;
    double x = bisect(func, 1.5, 2.5, 50);
    cout << "Lowest energy = " << 0.9525082255 * x*x - 10 << endl;

    return 0;
}
