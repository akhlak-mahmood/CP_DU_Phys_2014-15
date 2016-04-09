#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double mypi(int n)
{
    double prod = 1.0;
    double sum = 0.0;

    if(n<1) exit(1);

    for(int i=1; i<=n; i++) {
        prod *= 1.0 + 1.0 / (4.0*i*i - 1.0);
    }

    for(int i=1; i<=n; i++) {
        sum += 1.0 / (4*i*i - 1);
    }

    return prod / sum;
}


int main()
{
    ofstream data("lab1 data.dat");
    ofstream gnu("lab1 gnu.dat");

    for(int n=2; n<=20; n+=2) {
        cout << n << "  " << mypi(n) << endl;
        data << n << "  " << mypi(n) << endl;
    }

    data.close();

    for(int n=1; n<100; n++) {
        gnu << n << "  " << abs(mypi(n) - M_PI) << endl;
    }

    /// GNUPLOT:
    /// set terminal postscript
    /// set output "lab1.ps"
    /// plot "lab1 gnu.dat" w l

    return 0;
}
