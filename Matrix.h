#ifndef __MATRIX_H__
#define __MATRIX_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Matrix {
   public:
    int n;
    float **IdentityMatrix;
    float **InputMatrix;
    float **InverseMatrix;

    void SetN();
    float** initMatrix();
    float** SetInputMatrix();
    void pivot(float** InputMatrix, float** IdentityMatrix);
    void InverseMat(float** InputMatrix, float** IdentityMatrix);
    void freeArr(float** InputMatrix, float** IdentityMatrix);
};

#endif
