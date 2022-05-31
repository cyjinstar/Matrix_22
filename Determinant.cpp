#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    Matrix matrix;
    cout<<"determinant of n * n matrix"<<endl;
    int n = matrix.SetN();
    float** IdentityMat = matrix.initMatrix();
    float** InputMat = matrix.SetInputMatrix();
    cout<<"determinant is : "<<matrix.determinant(InputMat,n)<<endl;
}