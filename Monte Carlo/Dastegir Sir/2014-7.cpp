#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

double f(double x)
{
  return 1 - x;
}

double g(double x)
{
  return x;
}

double integral(int N)
{
  double x, y;
  int c = 0;
  
  for(int i=0; i<N; i++) {
    x = 0 + (0.5-0) * rand() / RAND_MAX;
    y = 0 + (1.0-0) * rand() / RAND_MAX;

    //cout << x << " " << y << " " << f(x) << " " << g(x) << endl;

    if(y > f(x) || y < g(x)) c++;
  }

  //cout << c << endl;

  return (double)c / (double)N * 0.5 + 0.5;
}


int main()
{
  srand(time(NULL));
  cout << integral(5000000) << endl;
  return 0;
}
