#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double trapezoid(double f(double), double a, double b, int N)
{
    if(N<1) exit(1);

    double h = (b-a)/(double) N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i++) {
        sum += 2 * f(a + i*h);
    }

    return h/2.0 * (f(a) + sum + f(b));
}


double simpson13(double f(double), double a, double b, int N)
{
    if(N<2 || N%2==1) exit(5);

    double h = (b-a)/(double)N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i+=2) {
        sum += 4 * f(a + i*h);
    }

    for(int i=2; i<=N-2; i+=2) {
        sum += 2 * f(a + i*h);
    }

    return h/3.0 * (f(a) + sum + f(b));
}


double ipow(int base, int p)
{
    if(p<0) exit(2);

    double prod = 1.0;
    for(int i=0; i<p; i++) {
        prod *= base;
    }

    return base;
}

double RombergT(int m, double f(double), double a, double b, int N)
{
    double tree[5][5];

    if(m<0) exit(3);
    if(m==0) return trapezoid(f, a, b, N);
    if(m>5) exit(4);

    tree[0][0] = trapezoid(f, a, b, N);

    for(int row=1; row<m; row++) {
        tree[row][0] = trapezoid(f, a, b, int(N * ipow(2, row)));

        for(int col=1; col<=row; col++) {
            tree[row][col] = (ipow(2, 2*col) * tree[row][col-1] - tree[row-1][col-1]) / ipow(2, 2*col);
        }
    }

    return tree[m-1][m-1];
}


double RombergS13(int m, double f(double), double a, double b, int N)
{
    if(N<2 || N%2==1) exit(6);
    if(m<0) exit(7);
    if(m==0) return simpson13(f, a, b, N);
    if(m>5) exit(8);

    double tree[5][5];

    tree[0][0] = simpson13(f, a, b, N);

    for(int row=1; row<m; row++) {
        tree[row][0] = simpson13(f, a, b, int(N * ipow(2, row)));

        for(int col=1; col<=row; col++) {
            tree[row][col] = (ipow(2, 2*col + 2) * tree[row][col-1]-tree[row-1][col-1]) / (ipow(2, 2*col + 2) - 1);
        }
    }

    return tree[m-1][m-1];
}

double I1(double x)
{
    return (cos(x) * log(sin(x)))/(1 + sin(x));
}

double I2(double x)
{
    return tan(x);
}

int main()
{
    cout.precision(10);
    cout << "Trapezoid I1 = " << trapezoid(I1, M_PI_4, M_PI_2, 50) << endl;
    cout << "Imporved I1 = " << RombergT(5, I1, M_PI_4, M_PI_2, 50) << endl;

    cout << "Trapezoid I2 = " << trapezoid(I2, 0, 3/8*M_PI, 50) << endl;
    cout << "Improved I2 = " << RombergT(5, I2, 0, 3/8*M_PI, 50) << endl;

    cout << "Simpson13 I1 = " << simpson13(I1, M_PI_4, M_PI_2, 50) << endl;
    cout << "Imporved I1 = " << RombergS13(5, I1, M_PI_4, M_PI_2, 50) << endl;

    cout << "Simpson13 I2 = " << simpson13(I2, 0, 3.0/8*M_PI, 50) << endl;
    cout << "Improved I2 = " << RombergS13(5, I2, 0, 3.0/8*M_PI, 50) << endl;

    return 0;
}
