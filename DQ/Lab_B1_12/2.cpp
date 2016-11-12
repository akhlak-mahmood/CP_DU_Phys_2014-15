#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double f(double t, double p, double q)
{
    return pow(t, p-1) * pow(1-t, q-1);
}

double simpson13(double p, double q)
{
    int N = 50;
    double a = 0;
    double b = 1;
    double h = (b - a) / (double) N;

    double sum = 0;
    for(int i=1; i<=N-1; i+=2) {
        sum += 4 * f(a+i*h, p, q);
    }
    for(int i=2; i<=N-2; i+=2) {
        sum += 2 * f(a+i*h, p, q);
    }

    return (h/3.0) * (f(a, p, q) + sum + f(b, p, q));
}

double betadist(double x, double p, double q)
{
    return pow(x, p-1) * pow(1-x, q-1) / simpson13(p, q);
}

int main()
{
    ofstream fout("2.txt");
    for(double x=0; x<=1; x+=0.01) {
        fout << x << "  " << betadist(x, 2, 2) << "  " << betadist(x, 3, 3) << endl;
        cout << x << "  " << betadist(x, 2, 2) << "  " << betadist(x, 3, 3) << endl;
    }

    return 0;
}
