#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

using namespace std;
//가우스-조르단 소거법을 이용하여 역행렬을 구하는 알고리듬
int main(){
    Matrix matrix;
    cout << "Reverse Calculator of n by n matrix"<< endl;
    int n = matrix.SetN(); //행렬의 크기 입력받음
    float** IdentityMat = matrix.initMatrix(); //행렬을 입력받음
    float** InputMat = matrix.SetInputMatrix();
    if (matrix.determinant(InputMat, n)){//det가 0이 아닐 때만 역행렬을 구함
        matrix.InverseMat(InputMat,IdentityMat);//가우스-조르단 소거법을 사용하여 역행렬을 구하고 출력함.
    }
    else {
        cout << "Determinant = 0. Can't invese the matrix." << endl;
        //만약 determinant가 0이라면 역행렬을 구할 수 없으므로 determinant가 0임을 출력하고 프로그램을 종료한다.
    }
    matrix.freeArr(InputMat,IdentityMat); //사용한 메모리 해제

    return 0;
}