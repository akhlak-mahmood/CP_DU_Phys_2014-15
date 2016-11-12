#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double M = 1.0;
double k = 1.0;
double w = 5.0;

double fx(double t, double x, double v)
{
  return v;
}

double fv(double t, double x, double v)
{
  return - (k/M) * x * exp( -(v/w));
}


void rk4(double h, double t, double &x, double &v)
{
  double k1, k2, k3, k4;
  double m1, m2, m3, m4;

  k1 = h * fx(t, x, v);
  m1 = h * fv(t, x, v);

  k2 = h * fx(t+h/2, x+k1/2, v+m1/2);
  m2 = h * fv(t+h/2, x+k1/2, v+m1/2);

  k3 = h * fx(t+h/2, x+k2/2, v+m2/2);
  m3 = h * fv(t+h/2, x+k2/2, v+m2/2);

  k4 = h * fx(t+h, x+k3, v+m3);
  m4 = h * fv(t+h, x+k3, v+m3);

  x += (k1 + 2*k2 + 2*k3 + k4)/6;
  v += (m1 + 2*m2 + 2*m3 + m4)/6;
}

int main()
{
  double x, v = 0.0, h=0.1;

  ofstream fout1("ms1.txt");
  x = 0.1;

  for(double t=0; t<=10; t+=h) {
    fout1 << t << "  " << x << "  " << v << endl;
    cout << t << "  " << x << "  " << v << endl;
    rk4(h, t, x, v);
  }

  fout1.close();

  ofstream fout2("ms2.txt");
  x = 1;
  v = 0;

  for(double t=0; t<=10; t+=h) {
    fout2 << t << "  " << x << "  " << v << endl;
    cout << t << "  " << x << "  " << v << endl;
    rk4(h, t, x, v);
  }

  fout2.close();

  ofstream fout3("ms3.txt");
  x = 10;
  v = 0;

  for(double t=0; t<=0.5; t+=h) {
    fout3 << t << "  " << x << "  " << v << endl;
    cout << t << "  " << x << "  " << v << endl;
    rk4(h, t, x, v);
  }

  fout3.close();

  return 0;
}
