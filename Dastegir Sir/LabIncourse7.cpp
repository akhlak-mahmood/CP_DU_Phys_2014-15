#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double mypi(int n)
{
    double a = 1.0;
    double b = 1.0 / sqrt(2);
    double t = 1.0/4.0;
    double p = 1.0;

    for(int i=1; i<=n; i++) {
        a = (a + b) / 2.0;
        b = sqrt(a*b);
        t = t + p * (a*a - b*b);
        p = 2 * p;
    }

    return (a + b) * (a + b) / 4.0 * t;
}

int main()
{
    ofstream fout("lab7.dat");

    double x;

    for(int n=2; n<=20; n+=2) {
        x = mypi(n);

        cout << n << "  " << x << "  " << abs(x - M_PI) << endl;
        fout << n << "  " << x << "  " << abs(x - M_PI) << endl;
    }

    fout.close();

    return 0;
}
