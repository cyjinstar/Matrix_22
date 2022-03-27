#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int* nbynImatrix();
int** enterMatrix();
void checkDet();
void reverseMat();

int n = 0;
int* Imatarr;
int **inputMatarr;

int main(){
    Imatarr = nbynImatrix();
    free(Imatarr);
    inputMatarr = enterMatrix();
    printf("%d, %d, %d, %d",inputMatarr[0][0], inputMatarr[0][1], inputMatarr[1][0], inputMatarr[1][1]);
    return 0;
}

int* nbynImatrix(){
    printf("Reverse Calculator of n by n matrix\n");
    printf("n = ? (n < 5)\n");
    scanf("%d",&n);
    if(n < 1 || n > 4){
        printf("unsuitable number.");
        exit(0);
    }
    int** Imatrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) { 
        Imatrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            if(i==j){
                Imatrix[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
    return *Imatrix;
}

int** enterMatrix(){
    int num = 0;
    int det = 0;
    printf("enter %d by %d Matrix\n",n, n);

    int** Inputmatrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) { 
        Inputmatrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            printf("enter [%d][%d] ", i + 1, j + 1);
            scanf("%d",&num);
            Inputmatrix[i][j] = num;
        }
    }

    if(n == 2){
        det = Inputmatrix[0][0] * Inputmatrix[1][1] - Inputmatrix[0][1] * Inputmatrix[1][0];
    }
    if(n == 3){
        det = Inputmatrix[0][0] * (Inputmatrix[1][1] * Inputmatrix[2][2] - Inputmatrix[1][2] * Inputmatrix[2][1])
        - Inputmatrix[0][1] * (Inputmatrix[1][0] * Inputmatrix[2][2] - Inputmatrix[1][2] * Inputmatrix[2][0])
        + Inputmatrix[0][2] * (Inputmatrix[1][0] * Inputmatrix[2][1] - Inputmatrix[1][1] * Inputmatrix[2][0]);
    }

    printf("det = %d\n",det);//testing

    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    return Inputmatrix;
}