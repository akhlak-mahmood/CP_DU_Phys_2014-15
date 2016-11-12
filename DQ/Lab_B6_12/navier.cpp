#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int sigma = 10;
double b = 8/3;

double fx(double r, double x, double y, double z)
{
  return sigma * (y-x);
}

double fy(double r, double x, double y, double z)
{
  return -x*z + r*x - y;
}

double fz(double r, double x, double y, double z)
{
  return x*y - b*z;
}


double rk4(double r, double h, double t, double &x, double &y, double &z)
{
  double k1, k2, k3, k4;
  double m1, m2, m3, m4;
  double n1, n2, n3, n4;

  k1 = h * fx(r, x, y, z);
  m1 = h * fy(r, x, y, z);
  n1 = h * fz(r, x, y, z);

  k2 = h * fx(r, x+k1/2, y+m1/2, z+n1/2);
  m2 = h * fy(r, x+k1/2, y+m1/2, z+n1/2);
  n2 = h * fz(r, x+k1/2, y+m1/2, z+n1/2);
  
  k3 = h * fx(r, x+k2/2, y+m2/2, z+n2/2);
  m3 = h * fy(r, x+k2/2, y+m2/2, z+n2/2);
  n3 = h * fz(r, x+k2/2, y+m2/2, z+n2/2);

  k4 = h * fx(r, x+k3, y+m3, z+n3);
  m4 = h * fx(r, x+k3, y+m3, z+n3);
  n4 = h * fx(r, x+k3, y+m3, z+n3);

  x += (k1 + 2*k2 + 2*k3 + k4)/6;
  y += (m1 + 2*m2 + 2*m3 + m4)/6;
  z += (n1 + 2*n2 + 2*n3 + n4)/6;
}


int main()
{
  ofstream fout("navier.txt");
  double r = 5;
  double x = 1;
  double y = 0;
  double z = 0;
  double h = 1;

  for(double t=0; t<=100; t+=h) {
    fout << t << "  " << x << "  " << y << "  " << z << endl;
    cout << t << "  " << x << "  " << y << "  " << z << endl;
    rk4(5, h, t, x, y, z);
  }

  return 0;
}
