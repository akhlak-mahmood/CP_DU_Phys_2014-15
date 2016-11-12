#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <climits>

using namespace std;

double f(double x)
{
  return cos(M_PI * x*x/2);
}

double g(double x)
{
  return sin(M_PI*x*x/2);
}

double C(double z, int N)
{
  int c = 0;
  double xi = 0, xf = z;
  double yi = 0, yf = 1;
  double x, y;

  for(int i=0; i<N; i++) {
    x = xi + (xf - xi) * rand()/RAND_MAX;
    y = yi + (yf - yi) * rand()/RAND_MAX;

    if(y < f(x)) c++;
  }

  return z * (double)c/(double)N;
}

double S(double z, int N)
{
  int c = 0;
  double xi = 0, xf = z;
  double yi = 0, yf = 1;
  double x, y;

  for(int i=0; i<N; i++) {
    x = xi + (xf - xi) * rand()/RAND_MAX;
    y = yi + (yf - yi) * rand()/RAND_MAX;

    if(y < g(x)) c++;
  }

  return z * (double)c/(double)N;
}

int main()
{
  double c1 = 0.779893400;
  double s1 = 0.438259147;
  double err1, err2;

  cout << INT_MAX << endl;

  ofstream fout("1.txt");

  for(int N=1; N<=7; N++) {
    err1 = abs(c1 - C(1, (int)pow(10, N)));
    err2 = abs(s1 - S(1, (int)pow(10, N)));
    
    fout << N << "  " << err1 << "  " << err2 << endl;
    cout << N << "  " << err1 << "  " << err2 << endl;
  }

  cout << "Done!" << endl;
  
  return 0;
}
