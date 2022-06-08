#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Matrix.h"
//determinant를 구하는 알고리듬
using namespace std;

int main(){
    Matrix matrix;
    cout<<"determinant of n * n matrix"<<endl;
    int n = matrix.SetN(); //행렬의 크기 입력받음
    float** InputMat = matrix.SetInputMatrix(); //행렬을 입력받음
    cout<<"determinant is : "<<matrix.determinant(InputMat,n)<<endl; //determinant를 구하고 출력함
}