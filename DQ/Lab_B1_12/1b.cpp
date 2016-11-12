#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

void euler2o(double w, double t, double h, double &x, double &z)
{
    x = x + z;
    z = z - w*w*x;
}


int main()
{
    double x = 0;
    double z = 1;
    double h = 0.01;

    double w = 1;
    ofstream fout("1b1.txt");
    for(double t=0; t<=0.5; t+=h) {
        fout << t << "  " << x << "  " << z << endl;
        cout << t << "  " << x << "  " << z << endl;

        euler2o(w, t, h, x, z);
    }
    fout.close();

    x=0, z = 1, w = 4;
    ofstream fout1("1b4.txt");
    for(double t=0; t<=0.5; t+=h) {
        fout1 << t << "  " << x << "  " << z << endl;
        cout << t << "  " << x << "  " << z << endl;

        euler2o(w, t, h, x, z);
    }
    fout1.close();

    x=0, z = 1, w = 9;
    ofstream fout2("1b9.txt");
    for(double t=0; t<=0.5; t+=h) {
        fout2 << t << "  " << x << "  " << z << endl;
        cout << t << "  " << x << "  " << z << endl;

        euler2o(w, t, h, x, z);
    }
    fout2.close();

    x=0, z = 1, w = 16;
    ofstream fout3("1b16.txt");
    for(double t=0; t<=0.5; t+=h) {
        fout3 << t << "  " << x << "  " << z << endl;
        cout << t << "  " << x << "  " << z << endl;

        euler2o(w, t, h, x, z);
    }
    fout3.close();

    return 0;
}
