#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double pFact(int n)
{
  if(n<0) exit(1);
  if(n==0) return 1;
  if(n==1) return sqrt(M_PI)/2;
  else return n/2 * pFact(n-2);
}


double f(double x, int v, double p)
{
  return exp(x*p) * pow(1 - p*p, v - 1/2);
}


double integrateS13(double x, int v)
{
  double a = -1;
  double b = 1;
  int N = 50;
  double h = (b-a)/N;

  double sum = 0;

  for(int i=1; i<=N-1; i+=2) {
    sum += 4 * f(x,v, a + i*h);
  }

  for(int i=2; i<=N-2; i+=2) {
    sum += 2 * f(x,v, a + i*h);
  }

  return h/3 * (f(x,v, a) + sum + f(x,v, b));
}


double BesselI(double x, int n)
{
  return pow(x/2, n) * integrateS13(x,n) / sqrt(M_PI) / pFact(2*(n - 1/2));
}


int main()
{
  ofstream fout("bessel.txt");

  for(double x=0; x<=3; x+=0.01) {
    cout << x << "  " << BesselI(x, 1) << "  " << BesselI(x, 2) << "  " << BesselI(x, 3) << endl;
    fout << x << "  " << BesselI(x, 1) << "  " << BesselI(x, 2) << "  " << BesselI(x, 3) << endl;
  }

  return 0;
}
