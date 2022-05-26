#include <iostream>
#include "Determinant.h"

using namespace std;

int main() {
    DetClass det;
    int n;
    cout<<"n?"<<endl;
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << det.determinant(matrix, n);

    return 0;
}