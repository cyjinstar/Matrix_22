#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"
#include "Determinant.h"

using namespace std;

int main(){
    Matrix matrix;
    DetClass det_c;
    int n = matrix.SetN();
    float** IdentityMat = matrix.initMatrix();
    float** InputMat = matrix.SetInputMatrix();
    if (det_c.determinant(InputMat,n)==0){
        cout<<det_c.determinant(InputMat,n)<<endl;
        cout<<"det = 0."<<endl;
    }
    else {
    det_c.detInvese(InputMat,n);
    }
    matrix.freeArr(InputMat,IdentityMat);

    return 0;
}