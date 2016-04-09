#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
    int  a = 10, b;
    b = a++ + ++a;

    cout << b << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << ++a << endl;


    a = -20;
    b = -3;

    cout << a%b << endl;

    int x=0, y=0;
    if(x==0 || ++y) cout << x << endl;
    cout << y << endl;

    int i=5, j=6;

    cout << (i|j) << endl;

    return 0;
}
