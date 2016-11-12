#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double f(double t)
{
  return exp(t*t);
}

double g(double t)
{
  return exp(-t*t);
}

double simpson38(double f(double), double a, double b, int N)
{
  if(N<3) exit(1);
  if(N%3 != 0) exit(2);
  
  double h = (b-a)/N;
  double sum = 0;

  for(int i=1; i<=N-2; i+=3) {
    sum += 3 * f(a + i*h);
  }
  for(int i=2; i<=N-2; i+=3) {
    sum += 3 * f(a + i*h);
  }
  for(int i=3; i<=N-3; i+=3) {
    sum += 2 * f(a + i*h);
  }

  return 3*h/8 * (f(a) + sum + f(b));
}

double ipow(int b, int p)
{
  if(p < 0) exit(5);
  double prod = 1;
  for(int i=0; i<p; i++) {
    prod *= b;
  }
  return prod;
}

double RombergS38(double f(double), int m, double a, double b, int N)
{
  double tree[5][5];
  if(m<0) exit(3);
  if(m==0) return simpson38(f, a, b, N);
  if(m>5) exit(4);

  tree[0][0] = simpson38(f, a, b, N);

  for(int row=1; row<m; row++) {
    tree[row][0] = simpson38(f, a, b, int(N * ipow(2, row)));

    for(int col=1; col<=row; col++) {
      tree[row][col] = (ipow(2, 2*col + 4) * tree[row][col-1] - tree[row-1][col-1])/(ipow(2, 2*col+4) - 1);
    }
  }

  return tree[m-1][m-1];
}


double dawpos(double x)
{
  return exp(-x*x) * RombergS38(f, 5, 0, x, 60);
}

double dawmin(double x)
{
  return exp(x*x) * RombergS38(g, 5, 0, x, 60);
}

int main()
{
  ofstream fout("daw.txt");

  for(double x=-6; x<=6; x+=0.1) {
    cout << x << "  " << dawpos(x) << "  " << dawmin(x) << endl;
    fout << x << "  " << dawpos(x) << "  " << dawmin(x) << endl;
  }

  return 0;
}
