#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;

int Matrix::SetN(){//����� ũ�⸦ �Է¹���
    cout << "n = ?"<< endl;
    scanf("%d",&n);

    return n;
}

float** Matrix::initMatrix(){ //initiate matrixes ����� �ʱ�ȭ �Լ�
    float** IdentityMatrixArr = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        IdentityMatrixArr[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
            if(i==j){
                IdentityMatrixArr[i][j] = 1.0; //�ִ밢������ ������ 1
            }
            else{
                IdentityMatrixArr[i][j] = 0.0; //�� ���� ��Ҵ� 0
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

float** Matrix::SetInputMatrix(){ //Input n*n Matrix ����� �Է¹޴� �Լ�
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
			if (inputmatrix[i][i] == 0) { //�౳ȯ
				for (int j = i + 1; j < n; j++) {
					if (inputmatrix[j][i] != 0) {
						swap(inputmatrix, identitymatrix, n, i, j);
						break;
					}
				}
				i--; // swap �����Ƿ� ���������δ� ����x
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
            InverseMatrix[i][j] = Matrix[j][i] / det; //���ڷ� ���� ����� ��ҵ��� determinant�� ������ ��� ���� ���� �ٲ۴�.
        }
    }
    return InverseMatrix;//�� ������ ���� ������� ��ȯ
}

float** Matrix::submatrix(float **matrix, int n, int x, int y){ //make sub matrix ���� ����� ����� �Լ�
     float **submatrix = new float *[n];
//n-1�� ũ��� ���� ��� �����ϳ� Ư�� ���ǿ��� �޸𸮻��� ������ �߻��Ͽ� ���� ����� ��ȯ���� �ʴ� ��Ȳ�� �߰ߵǾ���.
//�� ������ �ذ��ϱ� ���� n�� ũ���� �޸𸮸� �Ҵ��Ѵ�.
     int subi = 0;
     for (int i = 0; i < n; i++) {
         submatrix[subi] = new float[n];
         int subj = 0;
         if (i == y) {
             continue; //���� ���� ��Ŀ� �־ y���� �����Ѵ�.
         }
         for (int j = 0; j < n; j++) {
             if (j == x) {
                 continue; //���� ���� ��Ŀ� �־ x���� �����Ѵ�.
             }
             submatrix[subi][subj] = matrix[i][j];
             subj++;
         }
         subi++;
     }
     return submatrix;
 }

float Matrix::determinant(float **matrix, int n) {//determinant ��Ľ��� ���ϴ� �Լ�
    float det = 0;
    if (n == 1){
        return matrix[0][0]; // ũ�� 1�� ��Ŀ� ���ؼ��� determinant (�Ϲ������� ���� )
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]; //�Լ��� ���� �������� 2ũ���� ��Ŀ� ���� detminant ����
    }
    for (int x = 0; x < n; ++x) {
        det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
    }// ����Լ��ν� ����Ͽ� ������Ŀ� ���� determinant�Լ��� �����Ͽ� �̸� ���� determinant�� ���� �� �ִ�.
    return det;
}

float** Matrix::cofactor(float **matrix, int n){ //������ ����� ���ϴ� �Լ��̴�. �� �Լ��� ��ȯ���� adjointInverse �Լ��� ���ڷ� �־� ������� ���� �� �ִ�.
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
    for (int i = 0; i < n; i++) { //�Է¹��� ����� ����ϴ� �Լ��̴�.
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.2f  ", i+1, j+1, matrix[i][j]);
        }
        printf("\n");
    }
}

void Matrix::freeArr(float** Matrix1, float** Matrix2){//�Ҵ��� �޸𸮸� �����ϴ� �Լ�
    for (int i = 0; i < n; i++) {free(Matrix1[i]);}free(Matrix1);
    for (int i = 0; i < n; i++) {free(Matrix2[i]);}free(Matrix2);
    }//��� malloc �Լ��� �ƴ� new �����ڸ��� ���Ͽ� �����Ҵ��� �����Ͽ����� �ʿ���� �Լ��̴�.