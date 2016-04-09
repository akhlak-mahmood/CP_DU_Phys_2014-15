#include <iostream>
#include <cstdlib>
#include <cmath>

#include <fstream>

using namespace std;

double vf(double x, double a)
{
    return sqrt(2.0/M_PI) * x*x * exp((-1) * x*x / 2 * a*a) / a*a*a;
}

void velocities(double a, double *vavg, double *vrms)
{
    int N = 50;
    double lim1 = 0;
    double lim2 = 5 * a;

    double h = (lim2 - lim1) / N;
    double sum_avg = 0.0;
    double sum_rms = 0.0;

    sum_avg += lim1 * vf(lim1, a);
    sum_avg += lim2 * vf(lim2, a);
    sum_rms += lim1 * lim1 * vf(lim1, a);
    sum_avg += lim2 * lim2 * vf(lim2, a);

    for(int i=1; i<=N-1; i+=2){
        sum_avg += 4 * (lim1 + i*h) * vf(lim1 + i*h, a);
        sum_rms += 4 * (lim1 + i*h) * (lim1 + i*h) * vf(lim1 + i*h, a);
    }

    for(int i=2; i<=N-2; i++) {
        sum_avg += 2 * (lim1 + i*h) * vf(lim1 + i*h, a);
        sum_rms += 2 * (lim1 + i*h) * (lim1 + i*h) * vf(lim1 + i*h, a);
    }

    *vavg = h / 3.0 * sum_avg;
    *vrms = sqrt(h / 3.0 * sum_rms);
}


int main()
{
    ofstream fout("lab4.dat");
    double vavg;
    double vrms;

    for(double a=0.01; a<=2; a+=0.01)
    {
        velocities(a, &vavg, &vrms);
        cout << a << "  " << vavg << "  " << vrms << endl;
        fout << a << "  " << vavg << "  " << vrms << endl;
    }

    fout.close();

    return 0;
}
