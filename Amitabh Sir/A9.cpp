#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double a = 0.5;
double alpha = 0.05;
double c = 1.0;
double gamma = 0.9;

double f(double t, double x, double y)
{
    return a * x - alpha * x * y;
}

double g(double t, double x, double y)
{
    return -c * y + gamma * x * y;
}

void improved_euler(double t, double &x, double &y, double h)
{
    double xp, yp;
    xp = x + h*f(t, x, y);
    yp = y + h*g(t, x, y);
    x = x + (h/2) * (f(t, x, y) + f(t, xp, yp));
    y = y + (h/2) * (g(t, x, y) + g(t, xp, yp));
}


int main()
{
    double h = 0.1;
    double x = 1.0;
    double y = 0.5;

    ofstream fout("A9.txt");

    for(double t = 0.0; t <= 20; t += h)
    {
        cout << t << " " << x << " " << y << endl;
        fout << t << " " << x << " " << y << endl;

        improved_euler(t, x, y, h);
    }

    fout.close();

    return 0;
}
