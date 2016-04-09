#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

/// This one holds the integrand part, because we need to call it later several times
double integrand(double thetaM, double x)
{
    return pow(1 - sin(thetaM/2) * sin(thetaM/2) * sin(x) * sin(x), -0.5);
}

double Simpson13(double f(double, double), double thetaM, double xi, double xf, int N)
{
    double h = (xf - xi) / (double) N;
    double sum = 0.0;

    for(int i=1; i<=N-1; i+=2)
    {
        sum += 4.0 * f(thetaM, xi + i * h);
    }

    for(int i=2; i<=N-2; i+=2)
    {
        sum += 2.0 * f(thetaM, xi + i * h);
    }

    return (h/3.0) * (f(thetaM, xi) + sum + f(thetaM, xf));
}

/// thetaM is in radian
double pendulumT(double thetaM)
{
    if(thetaM < 0 || thetaM > M_PI) exit(1);

    /// for T=1 sec, 4*sqrt(L/g) = 2/Pi
    return 2 / M_PI * Simpson13(integrand, thetaM, 0, M_PI_2, 50);
}

int main()
{
    ofstream file("A6.txt");
    double checkpoints[] = {10, 50, 90};

    for(int i=0; i<3; i++)
    {
        /// before sending them in, we convert the given degrees in radians
        cout << checkpoints[i] << " Degree = " << pendulumT(checkpoints[i] * M_PI / 180) << endl;
    }

    cout << endl << endl;

    /// goes to std output
    for(double i=0; i<=M_PI; i += 0.15)
    {
        cout << i << " = " << pendulumT(i) << endl;
    }

    /// goes to data file
    for(double i=0; i<M_PI; i += 0.03)
    {
        file << i << " " << pendulumT(i) << endl;
    }

    /// always remember to close the file, its a good programming practice
    file.close();

    return 0;
}
