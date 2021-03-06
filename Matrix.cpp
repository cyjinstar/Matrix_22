#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int Matrix::SetN(){//행렬의 크기를 입력받음
    cout << "n = ?"<< endl;
    scanf("%d",&n);

    return n;
}

float** Matrix::initMatrix(){ //initiate matrixes 행렬의 초기화 함수
    float** IdentityMatrixArr = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        IdentityMatrixArr[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
            if(i==j){
                IdentityMatrixArr[i][j] = 1.0; //주대각선상의 성분은 1
            }
            else{
                IdentityMatrixArr[i][j] = 0.0; //그 외의 요소는 0
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

float** Matrix::SetInputMatrix(){ //Input n*n Matrix 행렬을 입력받는 함수
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
    int index = -1;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(InputMatrix[b][b] != 1){//주대각선상의 성분이 1이 아닐 때 1로 만듬
                if(InputMatrix[b][b] == 0){//주대각선상의 성분이 0일 경우
                    for(int i = 0; i < n; i++){
                        if(InputMatrix[i][b]!=0){//행렬의 0이 아닌 성분을 가진 행을 찾음
                            index = i;
                        }
                    }
                    for(int i = 0; i < n; i++){
                        if(b == n-1){//행렬의 맨 마지막행에 대한 연산에서 생기는 오류를 수정하기 위한 부분
                        r = InputMatrix[b-1][i];
                        InputMatrix[b][i] = InputMatrix[b][i] + r;
                        IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                        }
                        else{
                        r = InputMatrix[index][i]; //주대각선이 0인 행에 미리 검색한 0이 아닌 행의 성분을 더한다.
                        InputMatrix[b][i] = InputMatrix[b][i] + r;
                        IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                        }
                    }
                }
                
                float k = InputMatrix[b][b]; //해당 성분으로 성분이 속한 행의 요소들을 전부 나눠준다.
                for(int i = 0; i < n; i++){
                    InputMatrix[b][i] = InputMatrix[b][i] / k;
                    IdentityMatrix[b][i] = IdentityMatrix[b][i] / k;
                }
            }   
        }
    }
}

void Matrix::InverseMat(float** InputMatrix, float** IdentityMatrix){//Use Gauss-Jordan El. To InverseMatrix
    pivot(InputMatrix, IdentityMatrix);
    for(int j = 0; j < n; j++){ //make right triangle_Matrix
        for(int i = j; i < n-1; i++){//삼각행렬을 만드는 부분
            float k = 0;
            if(InputMatrix[i+1][j] == 0){
                continue;
            }
            k = (1 / InputMatrix[i+1][j]);
            for(int l = 0; l < n; l++){
                InputMatrix[i+1][l] = k * InputMatrix[i+1][l] - InputMatrix[j][l];
                IdentityMatrix[i+1][l] = k * IdentityMatrix[i+1][l] - IdentityMatrix[j][l];
            }
            printf("test\n");
                printMatrix(InputMatrix,n);
            pivot(InputMatrix, IdentityMatrix);
        }
    }

    for(int j=0;j<n;j++){//주대각선을 제외한 우측 상단의 요소들을 0으로 만드는 부분
        for(int i=j; i<n-1; i++){
            float r = InputMatrix[n-2-i][n-1-j];
            for(int l=0; l<n; l++){
                InputMatrix[n-2-i][l] = InputMatrix[n-2-i][l] - r * InputMatrix[n-1-j][l];
                IdentityMatrix[n-2-i][l] = IdentityMatrix[n-2-i][l] - r * IdentityMatrix[n-1-j][l];
            }
        }
    }
    printf("\n");
    printMatrix(InputMatrix,n);

for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            if(i==j){
                if(InputMatrix[i][j] != 1.0){
                    InverseMat(InputMatrix, IdentityMatrix);
                }
            }
            else{
                if(InputMatrix[i][j] != 0.0){
                    InverseMat(InputMatrix, IdentityMatrix);
                } //그 외의 요소는 0
            }
        }
    }

    cout << "\ninverse matrix"<< endl; //역행렬을 출력하는 부분
    for (int i = 0; i < n; i++) { //printmatrix함수를 사용하여 생략가능.
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
            InverseMatrix[i][j] = Matrix[j][i] / det; //인자로 받은 행렬의 요소들을 determinant로 나누고 행과 열을 서로 바꾼다.
        }
    }
    return InverseMatrix;//위 과정을 통해 역행렬을 반환
}

float** Matrix::submatrix(float **matrix, int n, int x, int y){ //make sub matrix 하위 행렬을 만드는 함수
     float **submatrix = new float *[n];
//n-1의 크기로 만들어도 사실 무방하나 특정 조건에서 메모리상의 오류가 발상하여 값이 제대로 반환되지 않는 상황이 발견되었음.
//이 문제를 해결하기 위해 n의 크기의 메모리를 할당한다.
     int subi = 0;
     for (int i = 0; i < n; i++) {
         submatrix[subi] = new float[n];
         int subj = 0;
         if (i == y) {
             continue; //새로 만들 행렬에 있어서 y행은 제외한다.
         }
         for (int j = 0; j < n; j++) {
             if (j == x) {
                 continue; //새로 만들 행렬에 있어서 x열은 제외한다.
             }
             submatrix[subi][subj] = matrix[i][j];
             subj++;
         }
         subi++;
     }
     return submatrix;
 }

float Matrix::determinant(float **matrix, int n) {//determinant 행렬식을 구하는 함수
    float det = 0;
    if (n == 1){
        return matrix[0][0]; // 크기 1의 행렬에 대해서의 determinant (일반적이지 않음 )
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]; //함수의 종료 조건이자 2크기의 행렬에 대한 detminant 공식
    }
    for (int x = 0; x < n; ++x) {
        det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
    }// 재귀함수로써 계속하여 하위행렬에 대한 determinant함수를 적용하여 이를 통해 determinant를 구할 수 있다.
    return det;
}

float** Matrix::cofactor(float **matrix, int n){ //여인자 행렬을 구하는 함수이다. 이 함수의 반환값을 adjointInverse 함수의 인자로 넣어 역행렬을 구할 수 있다.
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
    for (int i = 0; i < n; i++) { //입력받은 행렬을 출력하는 함수이다.
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.2f  ", i+1, j+1, matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix::freeArr(float** Matrix1, float** Matrix2){//할당한 메모리를 해제하는 함수
    for (int i = 0; i < n; i++) {free(Matrix1[i]);}free(Matrix1);
    for (int i = 0; i < n; i++) {free(Matrix2[i]);}free(Matrix2);
    }//사실 malloc 함수가 아닌 new 생성자만을 통하여 동적할당을 진행하였으면 필요없는 함수이다.