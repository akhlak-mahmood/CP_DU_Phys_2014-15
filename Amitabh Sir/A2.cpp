#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double prod(double q, int n)
{
    double product = 1.0;

    for(int i=1; i<=n; i++)
        product *= (i - q);

    return product;
}

double myfact(int n)
{
    if(n<0) exit(1);

    if(n==0) return 1.0;
    else return n * myfact(n-1);
}


int main()
{
    double x, p, q;
    double sum = 0.0;

    cout << "Enter x = ";
    cin >> x;

    cout << "Enter p = ";
    cin >> p;

    cout << "Enter q = ";
    cin >> q;

    // Impose the given conditions
    if(x<0 || x>1 || p<=0 || q<=0) exit(1);

    for(int n=0; n<=20; n++)
    {
        sum += prod(q, n) * pow(x, n+p) / (myfact(n) * (n+p));
    }

    cout << "Beta_"<< x << "(" << p << ", " << q << ") = " << sum << endl;

    return 0;
}
