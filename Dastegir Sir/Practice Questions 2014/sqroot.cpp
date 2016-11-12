#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double mysqroot(double b, int n)
{
  if(n<0) exit(1);
  if(b<0) exit(2);
  if(n==0) return 1.0;

  return (mysqroot(b, n-1) + b / mysqroot(b, n-1)) / 2;
}


double d(int i, int n)
{
  double r;
  r = mysqroot(i, n) - mysqroot(i-1, n);
  r -= 1 / ( mysqroot(i, n) + mysqroot(i-1, n) );
}


int main()
{
  ofstream fout("sqrt.txt");
  double r;

  cout << mysqroot(25, 10) << endl;

  for(int n=1; n<=20; n++) {
    r = mysqroot(100.0, n);
    fout << n << "  " << abs(sqrt(100) - r) << endl;
    cout << n << "  " << abs(sqrt(100) - r) << endl;
  }

  fout.close();

  for(int i=1; i<=100; i++) {
    cout << d(i, 10) << endl;
  }

  return 0;
}
