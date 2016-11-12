#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double yf(double t, double y, double v)
{
    return v;
}

double vf(double t, double y, double v)
{
    return - 4 * M_PI * M_PI * y;
}

void RK4(double h, double t, double &y, double &v)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    k1 = h * yf(t, y, v);
    m1 = h * vf(t, y ,v);

    k2 = h * yf(t+h/2, y+k1/2, v+m1/2);
    m2 = h * vf(t+h/2, y+k1/2, v+m1/2);

    k3 = h * yf(t+h/2, y+k2/2, v+m2/2);
    m3 = h * vf(t+h/2, y+k2/2, v+m2/2);

    k4 = h * yf(t+h, y+k3, v+m3);
    m4 = h * vf(t+h, y+k3, v+m3);

    y = y + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    v = v + (m1 + 2*m2 + 2*m3 + m4)/6.0;
}

int main()
{
    double h = 0.1;
    double y = 1;
    double v = 0;

    ofstream fout("rk4.txt");
    for(double t=0; t<=10; t+=h) {
        cout << t << "  " << y << "  " << v << endl;
        fout << t << "  " << y << "  " << v << endl;

        RK4(h, t, y, v);
    }

    return 0;
}
