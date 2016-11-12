#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double fact(int n)
{
  if(n<0) exit(1);
  if(n==1 || n==0) return 1;
  else return n * fact(n-1);
}

double dfact(int n)
{
  if(n<-1) exit(2);
  if(n==-1 || n==0) return 1;
  else return n * dfact(n-2);
}

double jn(double x, int n, int M)
{
  double sum = 0;

  for(int k=0; k<=M; k++) {
    sum += pow(-x*x/2, k)/(fact(k)*dfact(2*n+2*k+1));
  }

  return pow(x, n) * sum;
}

int main()
{
  int n=0;
  ofstream fout0("jn0.txt");

  for(double x=0; x<=10; x+=0.1) {
    cout << x << "   " << jn(x, n, 50) << endl;
    fout0 << x << "   " << jn(x, n, 50) << endl;
  }

  fout0.close();

  ofstream fout1("jn1.txt");
  n=1;
  for(double x=0; x<=10; x+=0.1) {
    cout << x << "   " << jn(x, n, 50) << endl;
    fout1 << x << "   " << jn(x, n, 50) << endl;
  }

  fout1.close();

  ofstream fout2("jn2.txt");
  n=2;
  for(double x=0; x<=10; x+=0.1) {
    cout << x << "   " << jn(x, n, 50) << endl;
    fout2 << x << "   " << jn(x, n, 50) << endl;
  }

  fout2.close();

  ofstream fout3("jn3.txt");
  n=3;
  for(double x=0; x<=10; x+=0.1) {
    cout << x << "   " << jn(x, n, 50) << endl;
    fout3 << x << "   " << jn(x, n, 50) << endl;
  }

  fout3.close();

  return 0;
}

