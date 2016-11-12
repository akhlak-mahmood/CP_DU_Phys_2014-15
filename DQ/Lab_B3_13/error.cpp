#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

double error(double x, int n)
{
  double prod, sum = 0;

  for(int i=0; i<n; i++) {
    prod = 1;
    for(int k=1; k<=i; k++) {
      prod *= (-x*x)/k;
    }

    sum += x * prod / (2*i + 1);
  }

  return 2 * (x + sum) / sqrt(M_PI);
}

int main()
{
  ofstream fout("err.txt");

  for(double x=0.0; x<=2.0; x += 2.0/300) {
    cout << x << "  " << error(x, 5) << "  " << error(x, 10) << "  " << error(x, 20) << endl;
    fout << x << "  " << error(x, 5) << "  " << error(x, 10) << "  " << error(x, 20) << endl;
  }

  cout << error(100, 100) << endl;
  return 0;
}
