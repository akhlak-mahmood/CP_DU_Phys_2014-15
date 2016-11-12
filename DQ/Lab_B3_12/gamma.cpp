#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;


double fact(int n)
{
  if(n<0) exit(1);
  if(n==0||n==1) return 1;
  else return n * fact(n-1);
}


double gamma(int m)
{
  return fact(m-1);
}

double gammadist(double x, int alpha, double beta)
{
  return pow(x, alpha-1) * exp(-x/beta)/pow(beta, alpha)/gamma(alpha);
}

double expectX(double x, int a, double b)
{
  return x * gammadist(x, a, b);
}

double expectX2(double x, int a, double b)
{
  return x*x * gammadist(x, a, b);
}


double simpson(double f(double, int, double), int alpha, double beta)
{
  double a = 0, b = 5000;
  int N = 1000;
  double h = (b-a)/N;
  double sum = 0;

  for(int i=1; i<=N-1; i+=2) {
    sum += 4 * f(a + i*h, alpha, beta);
  }

  for(int i=2; i<=N-2; i+=2) {
    sum += 2 * f(a + i*h, alpha, beta);
  }

  return h/3 * (f(a, alpha, beta) + sum + f(b, alpha, beta));
}

int main()
{
  double B = 2;
  double Ex, Ex2, var;

  ofstream fout("gamma.txt");

  
  for(int a=1; a<=4; a++) {
    Ex = simpson(expectX, a, B);
    Ex2= simpson(expectX2, a, B);
    var = Ex2 - Ex*Ex;
    cout << a << " has mean " << Ex << " and variance " << var << endl;
    fout << a << "  " << Ex << "  " << var << endl;
  }

  return 0;
}
