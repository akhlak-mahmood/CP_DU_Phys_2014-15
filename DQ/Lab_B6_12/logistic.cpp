#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double logistic(double a, double x0, int n)
{
    for(int i=0; i<n; i++) {
	x0 = a - x0*x0;
    }
    return x0;
}

int main()
{
    double x0 = 0.5;
    ofstream fout("logis.txt");

    for(int n=0; n<=100; n++) {
	fout << n << "  " << logistic(0.5, x0, n) << "  ";
	fout << logistic(1.476, x0, n) << "  " << logistic(2.0, x0, n) << endl;

	cout << n << "  " << logistic(0.5, x0, n) << "  ";
	cout << logistic(1.476, x0, n) << "  " << logistic(2.0, x0, n) << endl;
    }

    double a = 2;
    double x1=x0;
    double x2;
    
    ofstream gout("log2.txt");

    for(int n=0; n<=100; n++) {
	x2 = logistic(a, x0, n);
	cout << x1 << "  " << x2 << endl;
	gout << x1 << "  " << x2 << endl;
	x1 = x2;
    }

    return 0;
}
