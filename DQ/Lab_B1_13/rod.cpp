#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x)
{
  return 1/tan(x) - (x*x - 1)/2/x;
}


double bisect(double a, double b, double N)
{
  double e = 0.001;
  double d = 0.001;
  
  if(f(a)*f(b) > 0) exit(1);

  if(f(a) == 0) return a;
  if(f(b) == 0) return b;

  double x;
  
  for(int i=0; i<N; i++) {
    x = (a + b)/2;
    if(f(x) == 0) return x;

    if(abs(a-b) < e) return x;
    if(abs(f(x)) < d) return x;

    if(f(x)*f(b) < 0) a = x;
    else b = x;
  }

  return x;
}


int main()
{
  ofstream fout("rod.txt");
  
  for(double x=0; x<=2*M_PI; x+=0.1) {
    fout << x << " " << 1/tan(x) << "  " << (x*x - 1)/2/x << endl;
    cout << x << " " << 1/tan(x) << "  " << (x*x - 1)/2/x << endl;
  }

  cout << "The smallest positive root is " <<  bisect(1, 2, 50) << endl;

  return 0;
}
