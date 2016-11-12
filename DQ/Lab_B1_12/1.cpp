#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double mygold(int n)
{
    double prod = 1.0;

    for(int i=0; i<n; i++) {
        prod = 1 + 1 / prod;
    }

    return prod;
}


double myfibo(int n)
{
    return (pow(mygold(50), n+1) - pow(1 - mygold(50), n+1)) / (2 * mygold(50) - 1);
}

int main()
{
    cout << "Phi = " << mygold(50) << endl;

    for(int n=1; n<=11; n++) {
        cout << n << ": " << myfibo(n) << endl;
    }

    return 0;
}
