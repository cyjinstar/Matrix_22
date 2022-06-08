#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"
//cofactor 와 determinant를 이용하여 역행렬을 구하는 알고리듬
using namespace std;

int main(){
    Matrix matrix;
    cout << "Reverse Calculator of n by n matrix"<< endl;
    int n = matrix.SetN(); //행렬의 크기 입력받음
    float** InputMat = matrix.SetInputMatrix(); //행렬을 입력받음
    if (matrix.determinant(InputMat,n)==0){
        cout<<"det = 0."<<endl;
 //만약 determinant가 0이라면 역행렬을 구할 수 없으므로 determinant가 0임을 출력하고 프로그램을 종료한다.
    }
    else {
    float det = matrix.determinant(InputMat,n);
    float** cofactorMatrix = matrix.cofactor(InputMat,n); //여인자행렬을 구함
    float** Inverse = matrix.adjointInverse(cofactorMatrix, det, n); //구한 여인자행렬을 통해 역행렬을 구함
    matrix.printMatrix(Inverse, n); //역행렬 출력
    matrix.freeArr(cofactorMatrix,Inverse); //사용한 메모리 해제
    }
    return 0;
}