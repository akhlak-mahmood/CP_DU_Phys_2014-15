#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

double f(double x)
{
    return 1.0 / ( 1 + sin(x)*sin(x));
}

double integral2(unsigned long N)
{
    double x, xi = 0, xf = M_PI;
    double y, yi = 0, yf = 1;

    unsigned long c = 0;
    srand(time(NULL));

    for(unsigned long i=0; i<N; i++) {
        x = xi + (xf - xi) * rand() / (double) RAND_MAX;
        y = yi + (yf - yi) * rand() / (double) RAND_MAX;

        if(y <= f(x)) c++;
    }

    return M_PI * (double) c / (double) N;
}


int main()
{
    ofstream fout("1.txt");
    double val;
    for(unsigned long n=0; n<=7; n++) {
        val = integral2(pow(10, n));
        fout << n << "  " << abs(val - M_PI/sqrt(2)) << endl;
    }

    cout << val << endl;

    return 0;
}
