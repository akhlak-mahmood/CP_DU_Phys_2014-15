#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double factorial(int n)
{
  if(n<0) exit(1);
  if(n==0 || n==1) return 1.0;
  else return n * factorial(n-1);
}


double fresnel1(double x, int n)
{
  double sum = 0;
  for(int k=0; k<=n; k++) {
    sum += (pow(-1, k) * pow(M_PI_2, 2*k) * pow(x, 4*k+1)) / (factorial(2*k) * (4*k+1));
  }

  return sum;
}


int main()
{
  ofstream fout("fres.txt");
  int n = 20;

  for(double x=0; x<=20; x+=0.1) {
    fout << x << "  " << fresnel1(x, n) << endl;
    cout << x << "  " << fresnel1(x, n) << endl;
  }

  fout.close();

  cout << "x->inf = " << fresnel1(1000, 200) << endl;

  return 0;
}
