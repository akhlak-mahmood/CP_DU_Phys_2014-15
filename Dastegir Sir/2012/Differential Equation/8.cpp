#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double g = 9.8;
double a = 0.2;

double f(double t, double v)
{
    return g - a*v;
}

void improved_euler(double t, double &v, double h)
{
    double vp;
    vp = v + h * f(t, v);
    v = v + (h/2.0) * (f(t, v) + f(t, vp));
}

int main()
{
    double h = 0.1;
    double v = 0.0;

    ofstream fout("8.txt");

    for(double t=0.0; t<=40; t+=h)
    {
        cout << t << "  " << v << endl;
        fout << t << "  " << v << endl;

        improved_euler(t, v, h);
    }

    fout.close();

    return 0;
}
