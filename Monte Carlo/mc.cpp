#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

double f(double x)
{
  return x*x*x * exp(x);
}

double MC(double f(double), double a, double b, int N)
{
  double sum = 0;
  double x;

  for(int i=0; i<N; i++) {
    x = a + (b-a) * (rand()/RAND_MAX);
    sum = sum + f(x);
  }

  return (b-a)/N * sum;
}

int main()
{
  srand(time(NULL));
  cout << MC(f, -2, 2, 2000);
  return 0;
       r }
