#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double myfact(int n)
{
    if(n<0) exit(1);

    if(n==0) return 1.0;
    else return n * myfact(n-1);
}

double stirling(int n)
{
    // Its a factorial, not gonna expect a negative number here
    if(n<0) exit(1);

    return sqrt(2*M_PI*n) * pow(n, n) * exp(-n) * (1 + 1/(12*n) + 1/(288*n*n) - 139/(51840*n*n*n));
}

int main()
{
    for(int n=2; n<=12; n+=2)
    {
        // no : percentage of error
        cout << n << ": " << abs(myfact(n) - stirling(n))/myfact(n) * 100 << endl;
    }

    return 0;
}
