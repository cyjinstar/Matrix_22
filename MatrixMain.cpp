#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    Matrix matrix;
    matrix.SetN();
    float** IdentityMat = matrix.initMatrix();
    float** InputMat = matrix.SetInputMatrix();
    matrix.InverseMat(InputMat,IdentityMat);
    matrix.freeArr(InputMat,IdentityMat);

    return 0;
}