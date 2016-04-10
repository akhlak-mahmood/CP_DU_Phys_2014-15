#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return x*x*x*x - 5 * x*x*x - 10*x +3;
}

double fprime(double x)
{
    return 4*x*x*x - 15 * x*x - 10;
}

double NR(double ini_guess, int N)
{
    double x = ini_guess;
    for(int i=0; i<N; i++)
    {
        if(fprime(x) == 0) exit(1);
        x -= (f(x)/fprime(x));
    }

    return x;
}


int main()
{
    double guess;
    cout << "Enter the initial guess: ";
    cin >> guess;

    cout << NR(guess, 20) << endl;

    return 0;
}

