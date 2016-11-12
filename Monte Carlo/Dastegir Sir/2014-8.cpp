#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

double f(double x)
{
  return sqrt(1 - (x-1)*(x-1));
}

double g(double x)
{
  return 1 - sqrt(1-x*x);
}

double integral(int N)
{
  int c = 0;
  double x, y;

  for(int i=0; i<N; i++) {
    x = rand() / (double) RAND_MAX;
    y = rand() / (double) RAND_MAX;

    if(y < f(x) && y > g(x)) c++;
  }

  return (double)c / (double) N;
}

int main()
{
  cout << integral(50 * 1000) << endl;
  return 0;
}
