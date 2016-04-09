#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/// we are taking nm, not nm/2 as the parameter
double pfac(int nm)
{
    if(nm < 0) exit(67);
    else if(nm == 0) return 1.0;
    else if(nm == 1) return sqrt(M_PI) / 2.0;

    /// n! = n (n - 1)!
    return nm/2.0 * pfac(nm - 2);
}

int main()
{
    for(int n=0; n<=10; n++) {
        if(n%2==0) cout << n/2 <<"! = " << pfac(n) << endl;
        else cout << n <<"/2! = " << pfac(n) << endl;
    }

    return 0;
}
