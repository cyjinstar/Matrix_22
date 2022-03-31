#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

float** nbynImatrix();
float** enterMatrix();
void reverseMat();

int n = 0;
float **Imatarr;
float **inputMatarr;

int main(){
    Imatarr = nbynImatrix();
    printf("%.0f, %.0f, %.0f, %.0f \n",Imatarr[0][0], Imatarr[0][1], Imatarr[1][0], Imatarr[1][1]); //testing
    inputMatarr = enterMatrix();
    printf("%.0f, %.0f, %.0f, %.0f \n",inputMatarr[0][0], inputMatarr[0][1], inputMatarr[1][0], inputMatarr[1][1]); //testing
    reverseMat(inputMatarr,Imatarr,n);
    //free arrs_should do because of err.
    free(Imatarr);
    free(inputMatarr);
    return 0;
}

float** nbynImatrix(){ //Function that makes I_matrix
    printf("Reverse Calculator of n by n matrix\n");
    printf("n = ? (1 < n < 5)\n");
    scanf("%d",&n);
    if(n < 2 || n > 4){
        printf("unsuitable number.");
        exit(0);
    }
    float** Imatrix = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        Imatrix[i] = (float*)malloc(sizeof(float) * n);
        for (int j = 0; j < n; j++) {
            if(i==j){
                Imatrix[i][j] = 1.0;
            }
            else{
                Imatrix[i][j] = 0.0;
            }
        }
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.1f   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
    return Imatrix;
}

float** enterMatrix(){ //Input n*n Matrix & Investigate that det == 0 or not
    int num = 0;
    float det = 0;
    printf("enter %d by %d Matrix\n",n, n);

    float** Inputmatrix = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) { 
        Inputmatrix[i] = (float*)malloc(sizeof(float) * n);
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
    
    printf("det = %.1f\n",det);//testing
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.1f ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    return Inputmatrix;
}

void divi(float** Inputmatrix,float** Imatrix){
    for(int a = 0; a < n; a++){

        for(int b = 0; b < n; b++){

            if(Inputmatrix[a][b] != 1){
                float k = Inputmatrix[0][0];

                for(int i = 0; i < n; i++){
                    Inputmatrix[a][i] = Inputmatrix[a][i] / k;
                    Imatrix[a][i] = Imatrix[a][i] / k;
                    }
            }
        }
    }
}

void reverseMat(float** Inputmatrix, float** Imatrix, int n){ //아직 안돌아감, 계산이 안됨

    divi(Inputmatrix,Imatrix);

    for(int i = 1; i < n; i++){

        if(Inputmatrix[i][0] != 0){
        float k = Inputmatrix[i][0];

            for(int j = 0; j < n; j++){
                Inputmatrix[i][j] -= Inputmatrix[i-1][j] * k;
                Imatrix[i][j] -= Imatrix[i-1][j] * k;
                divi(Inputmatrix,Imatrix);
            }

        }
    }

    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
}