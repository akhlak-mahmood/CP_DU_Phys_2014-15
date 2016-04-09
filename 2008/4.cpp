#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void triangle()
{
    double a, b, c;
    double s, area;

    cout << "Enter the sides of triangle: " << endl;
    cin >> a >> b >> c;

    s = a + b + c;

    cout << "The perimeter is: " << endl;

    area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "The area is: " << area << endl;
}


void displaySum()
{
    double sum = 0.0;
    int n = 1;
    for(int i=0; i<15; i++) {
        sum += n;
        n *= 2;
    }

    cout << "Sum of the first 15 term is: " << sum << endl;
}

void trace()
{
    double mat[5][5];

    cout << "Enter a 5x5 mat"
    for(int r=0; r<5; r++) {
        for(int c=0; c<5; c++) {
            cout << "element " << r << c << " = ";
            cin >> mat[r][c];
        }
    }

    double sum = 0;

    for(int r=0; r<5; r++) {
        sum += mat[r][r];
    }

    cout << "The trace is: " << sum << endl;
}

int main()
{
    triangle();
    displaySum();
    trace();

    return 0;
}
