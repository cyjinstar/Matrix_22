#include <iostream>
#include "Determinant.h"

using namespace std;

int main() {
    DetClass det;
    int n;
    cout<<"n?"<<endl;
    cin >> n;
    float **matrix = new float *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new float[n];
        for (int j = 0; j < n; ++j) {
            cout << "enter " << i+1 << "," << j+1 << endl;
            cin >> matrix[i][j];
        }
    }

    cout << det.determinant(matrix, n);

    return 0;
}