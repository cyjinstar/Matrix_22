#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    Matrix matrix;
    cout << "Reverse Calculator of n by n matrix"<< endl;
    int n = matrix.SetN();
    float** IdentityMat = matrix.initMatrix();
    float** InputMat = matrix.SetInputMatrix();
    if (matrix.determinant(InputMat, n)){
        matrix.InverseMat(InputMat,IdentityMat);
    }
    else {
        cout << "Determinant = 0. Can't invese the matrix." << endl;
    }
    matrix.freeArr(InputMat,IdentityMat);

    return 0;
}