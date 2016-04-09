#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("A8.txt");

    double P = 101.325; // KPa
    double T = 293.15; // K
    double R = 8.314; // J/mol.K

    /// Values of a, b are taken from
    /// http://hyperphysics.phy-astr.gsu.edu/hbase/kinetic/waal.html
    double a = 0.547;
    double b = 30.53E-6;

    /// We'll be using Newton-Raphson method to solve for v here

    // initial guess
    double v = R*T/P;

    for(int i=0; i<50; i++)
    {
        /// X_n+1 = X_n - f(X_n)/f'(X_n) with X_n being the initial guess
        /// this is the pure NR method, not "secant" or "Quasi NR" method
        v = v - (P*v*v*v - (P*b + R*T)*v*v + a*v - a*b) / (3*P*v*v - 2*(P*b + R*T)*v + a);
    }

    cout << "The volume V is " << v << " cubic meter." << endl;

    for(v=0; v<30; v++)
    {
        fout << v << " " << P*v*v*v << " " << (P*b + R*T)*v*v - a*v + a*b << endl;
        /// GNUPLOT TIPS: plot "A8.txt" using 1:2 w l, "A8.txt" using 1:3 w l
    }

    fout.close();

    return 0;
}
