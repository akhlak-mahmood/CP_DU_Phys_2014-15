#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <stdio.h>

using namespace std;


void print_each_digit(int x)
{
    if(x >= 10)
       print_each_digit(x / 10);

    int digit = x % 10;

    std::cout << digit << '\n';
}

int main()
{

    return 0;
}
