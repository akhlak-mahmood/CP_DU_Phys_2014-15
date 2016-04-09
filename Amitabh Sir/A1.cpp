#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double myfact(int m)
{
    if(m<0) exit(1);

    if(m==0) return 1.0;
    else return m * myfact(m-1);
}

/// for B_m() and B_2n() where m=2n, we need to pass n, not 2n as the argument
double bernoulli(int n)
{
    double sum = 0.0;

    for(int p=1; p<=20; ++p)
    {
        sum += pow(p, -2*n);
    }

    return pow(-1, n-1) * 2 * myfact(2*n) / pow(2*M_PI, 2*n) * sum;
}

double testfunc(double x, int N)
{
    double sum = 0.0;

    for(int n=1; n<N; ++n){
        // for B_2n(), our bernoulli() accepts n, not 2n
        sum += bernoulli(n) * pow(x, 2*n) / myfact(2*n);
    }

    return 1.0 - x/2.0 + sum;
}

int main()
{
    for(int n=1; n<=20; ++n)
    {
        cout << "B(" << 2*n << ") = " << bernoulli(n) << endl;
    }

    cout << endl;

    for(double x=0.5; x<=2.0; x+=0.05)
    {
        double tested = testfunc(x, 30);
        double actual = x/(exp(x) - 1.0);

        cout << "For x=" << x << endl;
        cout << "Tested: " << tested << endl;
        cout << "Actual: " << actual << endl;
        cout << "Difference: " << abs(tested-actual) << endl;

        cout << endl;
    }

    return 0;
}
