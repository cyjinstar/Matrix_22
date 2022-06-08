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

void Matrix::swap(float** inputmatrix, float** unitmatrix, int n, int a, int b) {
		for (int i = 0; i < n; i++) {
			float temp1 = inputmatrix[a][i];
			inputmatrix[a][i] = inputmatrix[b][i];
			inputmatrix[b][i] = temp1;

			float temp2 = unitmatrix[a][i];
			unitmatrix[a][i] = unitmatrix[b][i];
			unitmatrix[b][i] = temp2;
		}
	}

void Matrix::GJInverse(float** inputmatrix, float** identitymatrix) {
		for (int i = 0; i < n; i++) {
			if (inputmatrix[i][i] == 0) { //행교환
				for (int j = i + 1; j < n; j++) {
					if (inputmatrix[j][i] != 0) {
						swap(inputmatrix, identitymatrix, n, i, j);
						break;
					}
				}
				i--; // swap 헀으므로 실직적으로는 실행x
			}
			else {
				float save1 = inputmatrix[i][i];
				for (int j = 0; j < n; j++) {
					inputmatrix[i][j] *= (1 / save1);
					identitymatrix[i][j] *= (1 / save1);
				}
				for (int j = i + 1; j < n; j++) {
					float index = inputmatrix[j][i];
					for (int k = 0; k < n; k++) {
						inputmatrix[j][k] -= (inputmatrix[i][k] * index);
						identitymatrix[j][k] -= (identitymatrix[i][k] * index);
					}
				}
			}
		}
		float index = inputmatrix[n - 1][n - 1];
		for (int i = 0; i < n; i++) {
			inputmatrix[n - 1][i] *= (1 / index);
			identitymatrix[n - 1][i] *= (1 / index);
		}
		for (int i = n - 1; i > 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				float index = inputmatrix[j][i];
				for (int k = 0; k < n; k++) {
					inputmatrix[j][k] -= (inputmatrix[i][k] * index);
					identitymatrix[j][k] -= (identitymatrix[i][k] * index);
				}
			}
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