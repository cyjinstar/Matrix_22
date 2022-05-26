#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::SetN(){
    cout << "Reverse Calculator of n by n matrix"<< endl;
    cout << "n = ?"<< endl;
    scanf("%d",&n);
}

float** Matrix::initMatrix(){ //initiate all matrixes
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

float** Matrix::SetInputMatrix(){ //Input n*n Matrix & Investigate that det == 0 or not
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

void Matrix::pivot(float** InputMatrix, float** IdentityMatrix){
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

void Matrix::InverseMat(float** InputMatrix, float** IdentityMatrix){
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

 void Matrix::freeArr(float** InputMatrix, float** IdentityMatrix){
    for (int i = 0; i < n; i++) {free(InputMatrix[i]);}free(InputMatrix);
    for (int i = 0; i < n; i++) {free(IdentityMatrix[i]);}free(IdentityMatrix);
    }