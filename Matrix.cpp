#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int Matrix::SetN(){
    cout << "Reverse Calculator of n by n matrix"<< endl;
    cout << "n = ?"<< endl;
    scanf("%d",&n);

    return n;
}

float** Matrix::initMatrix(){ //initiate matrixes
    float** IdentityMatrixArr = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        IdentityMatrixArr[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
            if(i==j){
                IdentityMatrixArr[i][j] = 1.0;
            }
            else{
                IdentityMatrixArr[i][j] = 0.0;
            }
        }
    }
    float** InverseMatrixArr = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) {
        InverseMatrixArr[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
                InverseMatrixArr[i][j] = 1.0;
            }
    }
    return IdentityMatrixArr;
}

float** Matrix::SetInputMatrix(){ //Input n*n Matrix
int num = 0;
printf("enter %d by %d Matrix\n",n, n);
    float** InputMatrixArr = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        InputMatrixArr[i] = (float*)malloc(sizeof(float) * n);
        for (int j = 0; j < n; j++) {
            printf("enter [%d][%d] ", i + 1, j + 1);
            scanf("%d",&num);
            InputMatrixArr[i][j] = num;
        }
    }
    return InputMatrixArr;
}

void Matrix::pivot(float** InputMatrix, float** IdentityMatrix){//func that needs when do Gauss-Jordan Matrix Inverse
    float r = 0;
    int index = 0;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(InputMatrix[b][b] != 1){
                if(InputMatrix[b][b] == 0){
                    for(int i = b; i < n; i++){
                        if(InputMatrix[i][b]!=0){
                            index = i;
                        }
                    }
                    for(int i = 0; i < n; i++){
                        if(b == n-1){
                        r = InputMatrix[b-1][i];
                        InputMatrix[b][i] = InputMatrix[b][i] + r;
                        IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                        }
                        else{
                        r = InputMatrix[index][i];
                        InputMatrix[b][i] = InputMatrix[b][i] + r;
                        IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                        }
                    }
                }
                
                float k = InputMatrix[b][b];
                for(int i = 0; i < n; i++){
                    InputMatrix[b][i] = InputMatrix[b][i] / k;
                    IdentityMatrix[b][i] = IdentityMatrix[b][i] / k;
                }
            }   
        }
    }
}

void Matrix::InverseMat(float** InputMatrix, float** IdentityMatrix){//Use Gauss-Jordan El. To InverseMatrix
    cout << "Inverse Start"<< endl;
    pivot(InputMatrix, IdentityMatrix);
    for(int j = 0; j < n; j++){
        for(int i = j; i < n-1; i++){
            float k = 0;
            if(InputMatrix[i+1][j] == 0){
                continue;
            }
            k = (1 / InputMatrix[i+1][j]);
            for(int l = 0; l < n; l++){
                InputMatrix[i+1][l] = k * InputMatrix[i+1][l] - InputMatrix[j][l];
                IdentityMatrix[i+1][l] = k * IdentityMatrix[i+1][l] - IdentityMatrix[j][l];
            }
            pivot(InputMatrix, IdentityMatrix);
        }
    }
    for(int j=0;j<n;j++){
        for(int i=j; i<n-1; i++){
            float r = InputMatrix[n-2-i][n-1-j];
            for(int l=0; l<n; l++){
                InputMatrix[n-2-i][l] = InputMatrix[n-2-i][l] - r * InputMatrix[n-1-j][l];
                IdentityMatrix[n-2-i][l] = IdentityMatrix[n-2-i][l] - r * IdentityMatrix[n-1-j][l];
            }
        }
    }
    cout << "\ninput matrix"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f  ", i+1, j+1, InputMatrix[i][j]);
        }
        printf("\n");
    }
    cout << "\ninverse matrix"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f  ", i+1, j+1, IdentityMatrix[i][j]);
        }
        printf("\n");
    }
}

float** Matrix::adjointInverse(float** Matrix, float det, int n){ //Inverse the matrix use determinant and adjoint of Matrix
    float** InverseMatrix = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) {
        InverseMatrix[i] = (float*)malloc(sizeof(float) * n);
        for (int j = 0; j < n; j++) {
            printf("%.1f, adj_det:%.1f\n",Matrix[j][i],det);
            InverseMatrix[i][j] = Matrix[j][i] / det;
            printf("%.1f\n",InverseMatrix[i][j]);
        }
    }
    return InverseMatrix;
}

float** Matrix::submatrix(float **matrix, int n, int x, int y){ //make sub matrix
     float **submatrix = new float *[n];
     int subi = 0;
     for (int i = 0; i < n; i++) {
         submatrix[subi] = new float[n];
         int subj = 0;
         if (i == y) {
             continue;
         }
         for (int j = 0; j < n; j++) {
             if (j == x) {
                 continue;
             }
             submatrix[subi][subj] = matrix[i][j];
             subj++;
         }
         subi++;
     }
     return submatrix;
 }

float Matrix::determinant(float **matrix, int n) {//determinant
    float det = 0;
    if (n == 1){
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int x = 0; x < n; ++x) {
        det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
    }
    return det;
}

float** Matrix::cofactor(float **matrix, int n){
    float** cofactorMatrix = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) {
        cofactorMatrix[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
                cofactorMatrix[i][j] = ((j+i) % 2 == 0 ? 1 : -1) * determinant(submatrix(matrix, n, j, i), n - 1);
            }
    }
     return cofactorMatrix;
}

void Matrix::printMatrix(float** matrix, int n){//print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.2f  ", i+1, j+1, matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix::freeArr(float** InputMatrix, float** IdentityMatrix){//free memory
    for (int i = 0; i < n; i++) {free(InputMatrix[i]);}free(InputMatrix);
    for (int i = 0; i < n; i++) {free(IdentityMatrix[i]);}free(IdentityMatrix);
    }