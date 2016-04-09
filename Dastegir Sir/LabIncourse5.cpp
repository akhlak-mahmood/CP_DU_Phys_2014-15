#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double myln2(int n)
{
    double sum = 0.0;

    for(int i=1; i<=n; i++) {
        sum += 1 / (i * pow(2, i));
    }

    return sum;
}


int main()
{
    ofstream fout("lab5.dat");
    double xn;

    for(int n=1; n<=30; n++) {
        xn = myln2(n);
        fout << n << "  " << xn << "  " << abs(log(2) - xn) << endl;
        cout << n << "  " << xn << "  " << abs(log(2) - xn) << endl;
    }
    fout.close();

    return 0;
}
