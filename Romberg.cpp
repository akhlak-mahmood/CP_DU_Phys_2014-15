// Using Romberg's method to improve numerical integral values
// mahmoodakhlak at gmail dot com

// You can watch these videos first for a theoretical introduction to Romberg's method
// Which might be very helpful for understanding this code
// https://www.youtube.com/watch?v=DZ8y6o3bUrM
// https://www.youtube.com/watch?v=RpNbjT4DFkQ

// Here we evaluate 4 different integrals
// Using 3 different methods (Trapezoidal, Simpson 1/3, Simpson 3/8)
// We also improve these 3 methods using Romberg's trick.

#include <iostream>
#include <cmath>
#include <cstdlib>

// Romberg Array size
#define MAX 5

using namespace std;

// Our functions definitions
double I1(double x)
{
    // 0 to Pi/2
    return 1.0 / (1 + sin(x));
}

double I2(double x)
{
    // 3 to 5
    return 1.0 / sqrt(x*x - 4);
}

double I3(double x)
{
    // -2 to 2
    return x*x*x*exp(x);
}

double I4(double x)
{
    // 0.5 to 1.5
    return (2 - 2*x + sin(x-1) + x*x) / (1 + (x-1)*(x-1));
}


// determines the integral using Trapezoidal rule
double trapezoid(double f(double), double a, double b, int N)
{
    if(N<1) exit(1);

    double h = (b-a) / (double)N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i++)
    {
        sum += 2 * f(a + i*h);
    }

    return (h/2.0) * (f(a) + sum + f(b));
}

// determines the integral using Simpson's 1/3 rule
double simpson13(double f(double), double a, double b, int N)
{
    if(N<2 || (N%2) == 1) exit(2);

    double h = (b-a) / (double) N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i+=2)
    {
        sum += 4 * f(a + i*h);
    }

    if(N>=2)
    {
        for(int i=2; i<=N-2; i+=2)
        {
            sum += 2 * f(a + i*h);
        }
    }

    return (h/3.0) * (f(a) + sum + f(b));
}

// determines the integral using Simpson's 3/8 rule
double simpson38(double f(double), double a, double b, int N)
{
    double h = (b-a) / (double) N;
    double sum = 0.0;

    for(int i=1; i<=N-2; i+=3)
    {
        sum += 3 * f(a + i*h);
    }

    for(int i=2; i<=N-2; i+=3)
    {
        sum += 3 * f(a + i*h);
    }

    for(int i=3; i<=N-3; i+=3)
    {
        sum += 2 * f(a + i*h);
    }

    return (3 * h / 8.0) * (f(a) + sum + f(b));
}

// custom power function for the Romberg operation
// we use this to avoid using cmath's heavy pow() function
double ipow(int b, int p)
{
    if(p<0) exit(9);

    double prod = 1.0;
    for(int i=0; i<p; i++)
        prod *= b;

    return prod;
}

// Romberg method using Simpson 1/3 rule to improve integral
double RombergS13(int order, double f(double), double a, double b, int N)
{
    /// The Romberg Tree
    double tree[MAX][MAX];

    /// Initialize the Romberg Tree with zeros
    for(int r = 0; r < MAX; r++)
        for(int c=0; c<MAX; c++)
            tree[r][c] = 0;

    /// Sanity check
    if(order < 0) exit(6);
    if(order > MAX) exit(7);

    /// Zero order Romberg means we need nothing to do
    if(order == 0) return simpson13(f, a, b, N);

    /// populate the [0,0] item, which is R(0, h)
    tree[0][0] = simpson13(f, a, b, N);

    for(int row=1; row<order; row++)
    {
        /// we populate the 0th column with R(0, h/2), R(0, h/4), R(0, h/8)
        /// h/2 means 2*N, h/4 means 4*N, h/8 means 8*N etc
        /// because h is inversely proportional to N -> h = (b-a)/N;
        tree[row][0] = simpson13(f, a, b, int(N * ipow(2, row)));
    }

    for(int row=1; row<order; row++)
    {
        /// determine [r,m] based on [r, m-1] and [r-1, m-1] using the Romberg's Simpson formula
        for(int m=1; m<=row; m++)
        {
            /// [r, m-1] corresponds to R(m-1, h/2)
            /// [r-1, m-1] corresponds to R(m-1, h)
            tree[row][m] = (ipow(2, 2*m+2) * tree[row][m-1] - tree[row-1][m-1]) / (ipow(2, 2*m+2) - 1);
        }
    }

    return tree[order-1][order-1];
}

double RombergS38(int order, double f(double), double a, double b, int N)
{
    /// The Romberg tree
    double tree[MAX][MAX];

    /// Initialize the tree with zeros
    for(int r=0; r<MAX; r++)
        for(int c=0; c<MAX; c++)
            tree[r][c] = 0;

    /// Sanity check
    if(order < 0 || order > MAX) exit(8);

    /// zero order = Simpson 3/8
    if(order == 0) return simpson38(f, a, b, N);

    /// populate the tree[0,0] with simpson
    tree[0][0] = simpson38(f, a, b, N);

    for(int row=1; row<order; row++)
    {
        /// we populate the 0th column with R(0, h/2), R(0, h/4), R(0, h/8)
        /// h/2 means 2*N, h/4 means 4*N, h/8 means 8*N etc
        /// because h is inversely proportional to N -> h = (b-a)/N;
        tree[row][0] = simpson13(f, a, b, int(N * ipow(2, row)));
    }

    for(int row=1; row<order; row++)
    {
        /// determine [r,m] based on [r, m-1] and [r-1, m-1] using the Romberg's Simpson formula
        for(int m=1; m<=row; m++)
        {
            /// [r, m-1] corresponds to R(m-1, h/2)
            /// [r-1, m-1] corresponds to R(m-1, h)
            tree[row][m] = (ipow(2, 2*m+4) * tree[row][m-1] - tree[row-1][m-1]) / (ipow(2, 2*m+4) - 1);
        }
    }

    return tree[order-1][order-1];
}

// Romberg method using Trapezoidal rule to improve integral
double RombergT(int m, double f(double), double a, double b, int N)
{
    double tree[MAX][MAX];
    for(int row=0; row<MAX; row++)
    {
        for(int col=0; col<MAX; col++)
            tree[row][col] = 0.0;
    }

    if(m<0) exit(4);
    if(m==0) return trapezoid(f, a, b, N);
    if(m>MAX) exit(5);

    tree[0][0] = trapezoid(f, a, b, N);

    for(int row=1; row<m; row++) {
        tree[row][0] = trapezoid(f, a, b, int(N * ipow(2, row)));

        for(int col=1; col<=row; col++) {
            tree[row][col] = (ipow(2, 2*col) * tree[row][col-1] - tree[row-1][col-1]) / (ipow(2, 2*col) - 1);
        }
    }

/*  // Debug purpose: view the Romberg tree
    for(int r=0; r<m; r++){
        for(int c=0; c<m; c++)
            cout << tree[r][c];
        cout << endl;
    }
*/
    return tree[m-1][m-1];
}



int main()
{
    // we want our values to be displayed until 20 decimal places
    cout.precision(20);

    cout << endl << "I1" << endl << "========================================" << endl;
    cout << "Trapezoidal: " << trapezoid(I1, 0, M_PI_2, 20) << endl;
    cout << "Romberg Improve: " << RombergT(5, I1, 0, M_PI_2, 20) << endl;

    cout << "Simpsons 1/3: " << simpson13(I1, 0, M_PI_2, 20) << endl;
    cout << "Romberg Improve: " << RombergS13(5, I1, 0, M_PI_2, 20) << endl;

    cout << "Simpsons 3/8: " << simpson38(I1, 0, M_PI_2, 20) << endl;
    cout << "Romberg Improve: " << RombergS38(5, I1, 0, M_PI_2, 20) << endl;

    cout << endl << "I2" << endl << "========================================" << endl;
    cout << "Trapezoidal: " << trapezoid(I2, 3, 5, 20) << endl;
    cout << "Romberg Improve: " << RombergT(5, I2, 3, 5, 20) << endl;

    cout << "Simpsons 1/3: " << simpson13(I2, 3, 5, 20) << endl;
    cout << "Romberg Improve: " << RombergS13(5, I2, 3, 5, 20) << endl;

    cout << "Simpsons 3/8: " << simpson38(I2, 3, 5, 20) << endl;
    cout << "Romberg Improve: " << RombergS38(5, I2, 3, 5, 20) << endl;

    cout << endl << "I3" << endl << "========================================" << endl;
    cout << "Trapezoidal: " << trapezoid(I3, -2, 2, 20) << endl;
    cout << "Romberg Improve: " << RombergT(5, I3, -2, 2, 20) << endl;

    cout << "Simpsons 1/3: " << simpson13(I3, -2, 2, 20) << endl;
    cout << "Romberg Improve: " << RombergS13(5, I3, -2, 2, 20) << endl;

    cout << "Simpsons 3/8: " << simpson38(I3, -2, 2, 20) << endl;
    cout << "Romberg Improve: " << RombergS38(5, I3, -2, 2, 20) << endl;

    cout << endl << "I4" << endl << "========================================" << endl;
    cout << "Trapezoidal: " << trapezoid(I4, 0.5, 1.5, 20) << endl;
    cout << "Romberg Improve: " << RombergT(5, I4, 0.5, 1.5, 20) << endl;

    cout << "Simpsons 1/3: " << simpson13(I4, 0.5, 1.5, 20) << endl;
    cout << "Romberg Improve: " << RombergS13(5, I4, 0.5, 1.5, 20) << endl;

    cout << "Simpsons 3/8: " << simpson38(I4, 0.5, 1.5, 20) << endl;
    cout << "Romberg Improve: " << RombergS38(5, I4, 0.5, 1.5, 20) << endl;

    return 0;
}
