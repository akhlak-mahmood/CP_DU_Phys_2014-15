#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number to check: ";
    cin >> n;

    int sum = n;

    while(n > 0) {
        sum -= (n%10) * (n%10) * (n%10);
        n = n / 10;
    }

    if(sum==0) cout << "Armstrong! " << endl;
    else cout << "Not Armstrong! " << endl;

    return 0;
}
