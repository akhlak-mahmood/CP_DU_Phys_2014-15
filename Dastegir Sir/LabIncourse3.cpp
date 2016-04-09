#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double my2bpi(int n)
{
    if(n<1) exit(1);

    double prod = 1.0;
    double a = 0;

    for(int i=1; i<=n; i++) {
        // when i == 1, a = sqrt(2)
        a = sqrt(2 + a);
        prod *= a/2.0;
    }

    return prod;
}

int main()
{
    ofstream fout("lab3.dat");

    for(int n=2; n<=20; n+=2) {
        cout << n << "  " << my2bpi(n) << "  " << abs(my2bpi(n) - 2.0/M_PI) << endl;
        fout << n << "  " << my2bpi(n) << "  " << abs(my2bpi(n) - 2.0/M_PI) << endl;
    }
    fout.close();

    return 0;
}
