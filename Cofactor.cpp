#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"
#include "Determinant.h"

using namespace std;

int main(){
    Matrix matrix;
    int n = matrix.SetN();
    float** IdentityMat = matrix.initMatrix();
    float** InputMat = matrix.SetInputMatrix();
    if (matrix.determinant(InputMat,n)==0){
        cout<<matrix.determinant(InputMat,n)<<endl;
        cout<<"det = 0."<<endl;
    }
    else {
    cout<<matrix.determinant(InputMat,n)<<endl;
    float det = matrix.determinant(InputMat,n);
    float** cofactorMatrix = matrix.cofactor(InputMat,n);
    float** beforeInverse = matrix.adjointInverse(cofactorMatrix, det, n);
    matrix.printMatrix(beforeInverse, n);
    matrix.freeArr(cofactorMatrix,beforeInverse);
    }
    return 0;
}