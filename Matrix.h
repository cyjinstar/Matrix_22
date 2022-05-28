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

    int SetN();
    float** initMatrix();
    float** SetInputMatrix();
    void pivot(float** InputMatrix, float** IdentityMatrix);
    void InverseMat(float** InputMatrix, float** IdentityMatrix);
    float** adjointInverse(float** Matrix, float det, int n);
    float **submatrix(float **matrix, int n, int x, int y);
    float determinant(float **matrix, int n);
    float **cofactor(float **matrix, int n);
    void printMatrix(float** matrix, int n);
    void freeArr(float** InputMatrix, float** IdentityMatrix);
};

#endif
