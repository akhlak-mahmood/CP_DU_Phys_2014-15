#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double myarctan(double x, int n)
{
    if(n<0) exit(1);
    if(n==0) return x / (1 + x*x);
    double p = 1;
    for(; n>0; n--) {
        int A = 2*n - 1;
        p = A + (n*x) * (n*x) / p;
    }

    return x/p;
}

int main()
{
    ofstream fout("1.txt");
    double x = 1.0;
    double res;

    for(int n=0; n<=20; n++) {
        res = myarctan(x, n);
        cout << n << "  " << res << "  " << abs(res - atan(x)) << endl;
        fout << n << "  " << res << "  " << abs(res - atan(x)) << endl;
    }

    /**
    Now on the GNUPLOT:
        > set terminal postscript
        > set output "mygraph.ps"
        > plot "1.txt" u 1:3 w l
    */


    return 0;
}
