#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double A = 10.498597;

int main()
{
    ofstream fout("5.dat");
    for(double x=0.01; x<=M_PI; x+=0.01) {
        cout << x << "  " << - 1/tan(x) << "  " << sqrt(A - x*x) << endl;
        fout << x << "  " << - 1/tan(x) << "  " << sqrt(A - x*x) << endl;
    }

    /// gnuplot
    /// > plot "5.dat" u 1:2 w l, "5.dat" u 1:3 w l

    return 0;
}
