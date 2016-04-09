#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double prodcosh(double x, int n)
{
    if(n<1) exit(1);

    double prod = 1;
    for(int k=1; k<=n; k++) {
        prod *= 1 + 4 * x*x / ( (2*k -1)*(2*k-1) * M_PI*M_PI );
    }

    return prod;
}


int main()
{
    // cosh(5) = 74.2
    cout << prodcosh(5, 1000) << endl;

    return 0;
}
