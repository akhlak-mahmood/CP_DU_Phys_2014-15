#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double dfact(int n)
{
    if(n<-1) exit(1);

    if(n==0 || n==-1) return 1.0;
    else return n * dfact(n-2);
}

double ellipticE(double m)
{
    double sum = 0.0;

    // impose the given conditions
    if(m<0 || m>=1) exit(1);

    // We first calculate the sum part
    for(int n=1; n<=20; n++)
    {
        sum += pow(dfact(2*n-1) / dfact(2*n), 2) * pow(m, n) / (2*n-1);
    }

    return M_PI/2*(1-sum);
}

int main()
{
    for(double m=0; m<1.0; m+=0.05)
    {
        cout << "E("<< m << ") = " << ellipticE(m) << endl;
    }

    return 0;
}
