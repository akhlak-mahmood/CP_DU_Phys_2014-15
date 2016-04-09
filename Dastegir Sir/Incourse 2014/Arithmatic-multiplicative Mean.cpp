#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double artmul(double x, int n)
{
    double a = x;
    double b = 1;

    for(int i=0; i<n; i++) {
        a = (a + b) / 2.0;
        b = sqrt(a * b);
    }

    return a;
}


int main()
{
    for(int n=1; n<=10; n+=1) {
        cout << n << "  " << artmul(0.1, n) << endl;
    }

    return 0;
}
