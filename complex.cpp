#include <iostream>
#include <complex>
#include <cstdlib>

using namespace std;

int main()
{
    complex<double> A[3][3];

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << "A" << i << j << " = ";
            cin >> A[i][j];
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(A[i][j] != conj(A[j][i])) {
                cout << "A is not hermitian.";
                exit(0);
            }
        }
    }
    cout << "A is hermitian." << endl;

    return 0;
}
