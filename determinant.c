#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

float** enterMatrix();
void MakeMatrix();
float determinant();
void testing();

int n = 0;
float **inputMatarr;

int main(){
    printf("Project Determinant.\n");
    printf("n = ? (1 < n < 5)\n");
    scanf("%d",&n);
    inputMatarr = enterMatrix();
    MakeMatrix(inputMatarr, n, 1);
    determinant(inputMatarr, n);

    return 0;
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
    testing(Inputmatrix);

    return Inputmatrix;
}

void MakeMatrix(float** InputMatrix, int cnt, int index){
    cnt--;
    float** Newmatrix = (float**)malloc(sizeof(float*) * cnt);
    for (int i = 0; i < cnt; i++) {
        Newmatrix[i] = (float*)malloc(sizeof(float) * cnt);
        for (int j = 0; j < cnt; j++) {
            Newmatrix[i][j] = InputMatrix[i][j];
        }
    }
    testing(Newmatrix);
}

float determinant(float** InputMatrix, int cnt){
    float** InptMrxInDet = InputMatrix;
    int x = 0;
    int y = 0;
    for(int i = 0; i < cnt; i++){
        MakeMatrix(InputMatrix,cnt,i);
    }
}


void testing(float** Inputmatrix){
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.1f ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
}

// float determinant(float** InputMatrix, int cnt){ //at first, cnt by cnt matrix

//     float** InptMrxInDet = InputMatrix;
//     if(cnt == 2){
//         float answer = InptMrxInDet[0][0] * InptMrxInDet[1][1] - InptMrxInDet[0][1] * InptMrxInDet[1][0];
//         return answer;
//     }
//     printf("\n");
//     for(int i = 0; i < n; i++) { //testing
//         for (int j = 0; j < n; j++) {
//             printf("arr[%d][%d] : %.0f  ", i+1, j+1, InptMrxInDet[i][j]);
//         }
//         printf("\n");
//     }

//     determinant(InptMrxInDet,--cnt);
// }