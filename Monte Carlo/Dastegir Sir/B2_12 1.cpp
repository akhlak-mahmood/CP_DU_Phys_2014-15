#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

double f(double x)
{
    return 2.0 / (1.0 + x*x);
}

double integral2(unsigned long N)
{
    double x, y, a=-1, b=1, c=0.0, d=2.0;
    int count=0;
    srand(time(NULL));

    for (unsigned long i=1; i<=N; i++)
    {
        x = a + (b-a) * rand()/(double) RAND_MAX;
        y = c + (d-c) * rand()/(double) RAND_MAX;

        //cout << x << "  " << y << "  " << f(x) << endl;

        if(y < f(x)) count++;
    }

    cout << count << endl;
    double ratio = (double)count / (double)N;
    return ratio * 4.0;
}

int main()
{
    cout<<integral2(50000)<<endl;
    return 0;
}
