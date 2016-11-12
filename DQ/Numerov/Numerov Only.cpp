#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double U(double t)
{
    return 0;
}

double V(double t)
{
    return - 4 * M_PI * M_PI;
}


double F(double t, double y)
{
    return U(t) + V(t) * y;
}

double getY1(double h, double t, double y, double yd)
{
    double u1 = U(t + h);
    double u2 = U(t + 2*h);
    double v1 = V(t + h);
    double v2 = V(t + 2*h);
    double f0 = F(t, y);
    double h4 = h*h*h*h;

    double y1;

    y1 = y * (1 - v2*h*h/24.0) + h * yd * (1 - v2 * h*h/12.0);
    y1 += h*h * (7*f0 + 6*u1 - u2)/24.0 - h4 * v2/36.0 * (f0 + 2*u1);
    y1 /= (1 - v1*h*h/4.0 + v1*v2*h4/18.0);

    return y1;
}

double getNewY(double h, double t, double y, double yOld)
{
    double ynew;
    ynew = 2*y - yOld + h*h/12 * (U(t+h) + 10*F(t, y) + F(t-h, yOld));
    ynew /= (1 - V(t+h) *h*h/12);
    return ynew;

}


int main()
{
    double h = 0.1;
    double ti = 0;
    double y = 1;
    double yd = 0;
    double yold, ynew;

    ofstream fout("numerov1.txt");

    for(double t=0; t <=10; t=t+h) {
        cout << t << "  " << y << endl;
        fout << t << "  " << y << endl;

	if(t==ti) {
            ynew = getY1(h, t, y, yd);
        }
        else {
            ynew = getNewY(h, t, y, yold);
        }

        yold = y;
        y = ynew;
    }

    return 0;
}
