#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int** nbynImatrix();
int** enterMatrix();
void reverseMat();

int n = 0;
int **Imatarr;
int **inputMatarr;

int main(){
    Imatarr = nbynImatrix();
    printf("%d, %d, %d, %d \n",Imatarr[0][0], Imatarr[0][1], Imatarr[1][0], Imatarr[1][1]); //testing
    inputMatarr = enterMatrix();
    printf("%d, %d, %d, %d \n",inputMatarr[0][0], inputMatarr[0][1], inputMatarr[1][0], inputMatarr[1][1]); //testing
    reverseMat(inputMatarr,Imatarr,n);
    //free arrs_should do because of err.
    free(Imatarr);
    free(inputMatarr);
    return 0;
}

int** nbynImatrix(){ //Function that makes I_matrix
    printf("Reverse Calculator of n by n matrix\n");
    printf("n = ? (1 < n < 5)\n");
    scanf("%d",&n);
    if(n < 2 || n > 4){
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
            else{
                Imatrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
    return Imatrix;
}

int** enterMatrix(){ //Input n*n Matrix & Investigate that det == 0 or not
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

    if(det == 0){ // if det == 0, there is no reversed matrix
        printf("Can't be reversed!!");
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

void reverseMat(int** Inputmatrix, int** Imatrix, int n){ //아직 안돌아감, 계산이 안됨
    int row = 0;
    int col = 0;

    if(Inputmatrix[0][0] != 1){
        for(int i = 0; i < n; i++){  
        Inputmatrix[0][i] = Inputmatrix[0][i] / Inputmatrix[0][0];
        Imatrix[0][i] = Imatrix[0][i] / Inputmatrix[0][0];
        }
    }

    for(int i = 1; i < n; i++){

        if(Inputmatrix[i][0] != 0){
        int k = Inputmatrix[i][0];

            for(int j = 0; j < n; j++){
                Inputmatrix[i][j] -= Inputmatrix[i-1][j] * k;
                Imatrix[i][j] -= Imatrix[i-1][j] * k;
            }

        }
    }

    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
}