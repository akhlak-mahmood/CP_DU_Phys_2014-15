#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void input3x3Matrix(int arr[3][3])
{
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << "element " << row+1 << col+1 << " = ";
            cin >> arr[row][col];
            cout << endl;
        }
    }
}

void print3x3Matrix(int arr[3][3])
{
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << "element " << row+1 << col+1 << " = " << arr[row][col];
            cout << endl;
        }
    }
}

void add3x3Matrix(int arr1[3][3], int arr2[3][3], int result[3][3])
{
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            result[row][col] = arr1[row][col] + arr2[row][col];
        }
    }
}

void multiply3x3Matrix(int arr1[3][3], int arr2[3][3], int result[3][3])
{
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                result[i][k] += arr1[i][j] * arr2[j][k];
            }
        }
    }
}

void print3x3MatrixElement(int arr[3][3], int row, int col)
{
    cout << "Element " << row << col << " = " << arr[row-1][col-1] << endl;
}

int main()
{
    int mat1[3][3];
    int mat2[3][3];
    int res[3][3];

    cout << "Enter matrix 1 " << endl;
    input3x3Matrix(mat1);

    cout << "Enter matrix 2 " << endl;
    input3x3Matrix(mat2);

    add3x3Matrix(mat1, mat2, res);
    cout << "The addition is " << endl;
    print3x3Matrix(res);

    multiply3x3Matrix(mat1, mat2, res);
    cout << "The multiplication is " << endl;
    print3x3Matrix(res);

    return 0;
}
