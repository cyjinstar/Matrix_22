#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Matrix {
   public:
    int n;
    float **IdentityMatrix;
    float **InputMatrix;
    float **InverseMatrix;

    void SetN(){
        std::cout << "Reverse Calculator of n by n matrix"<< std::endl;
        std::cout << "n = ?"<< std::endl;
        scanf("%d",&n);
    }
    void initMatrix(){ //initiate all matrixes
        float** IdentityMatrix = (float**)malloc(sizeof(float*) * n);
        for (int i = 0; i < n; i++) { 
            IdentityMatrix[i] = (float*)malloc(sizeof(float) * n);
                for (int j = 0; j < n; j++) {
                if(i==j){
                    IdentityMatrix[i][j] = 1.0;
                }
                else{
                    IdentityMatrix[i][j] = 0.0;
                }
            }
        }
        float** InverseMatrix = (float**)malloc(sizeof(float*) * n);
        for (int i = 0; i < n; i++) {
            InverseMatrix[i] = (float*)malloc(sizeof(float) * n);
                for (int j = 0; j < n; j++) {
                    InverseMatrix[i][j] = 1.0;
                }
        }
    }

    void SetInputMatrix(){ //Input n*n Matrix & Investigate that det == 0 or not
    int num = 0;
    printf("enter %d by %d Matrix\n",n, n);

        InputMatrix = (float**)malloc(sizeof(float*) * n);
        for (int i = 0; i < n; i++) { 
            InputMatrix[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
                printf("enter [%d][%d] ", i + 1, j + 1);
                scanf("%d",&num);
                InputMatrix[i][j] = num;
            }
        }
    }

    void pivot(){

        float r = 0;
        int index = 0;

        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){

                if(InputMatrix[b][b] != 1){

                    if(InputMatrix[b][b] == 0){
                        for(int i = b; i < n; i++){
                            if(InputMatrix[i][b]!=0){
                                index = i;
                            }
                        }
                    }
                    else{
                        for(int i = 0; i < n; i++){
                            if(b == n-1){
                            r = InputMatrix[b-1][i];
                            InputMatrix[b][i] = InputMatrix[b][i] + r;
                            IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                            }
                            else{
                            r = InputMatrix[index][i];
                            InputMatrix[b][i] = InputMatrix[b][i] + r;
                            IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                            }
                        }
                    }
                    
                    float k = InputMatrix[b][b];
                    printf("k = %f\n",k);
                    for(int i = 0; i < n; i++) { //testing
                        for (int j = 0; j < n; j++) {
                            printf("arr[%d][%d] : %.1f  ", i+1, j+1, InputMatrix[i][j]);
                        }
                    printf("\n");
                    }

                    printf("k2 = %f\n",k);

                    for(int i = 0; i < n; i++){
                        printf("i = %d, n = %d\n",i,n);
                        InputMatrix[b][i] = InputMatrix[b][i] / k;
                        printf("input 11 : %f\n",InputMatrix[b][i]);
                        IdentityMatrix[b][i] = IdentityMatrix[b][i] / k;
                    }
                }

                    printf("\n");
                    printf("%d, %d\n", a, b);
                    for(int i = 0; i < n; i++) { //testing
                        for (int j = 0; j < n; j++) {
                            printf("arr[%d][%d] : %.1f  ", i+1, j+1, InputMatrix[i][j]);
                        }
                    printf("\n");
                    }
            }

        }
    }

    void InverseMat(){
        std::cout << "Inverse Start"<< std::endl;
        pivot(); // executing is stop here. why?
        for(int j = 0; j < n; j++){
            for(int i = j; i < n-1; i++){
                std::cout << "Sequece : "<< i << std::endl;
                float k = 0;
                if(InputMatrix[i+1][j] == 0){
                    continue;
                }
                k = (1 / InputMatrix[i+1][j]);
                for(int l = 0; l < n; l++){
                    InputMatrix[i+1][l] = k * InputMatrix[i+1][l] - InputMatrix[j][l];
                    IdentityMatrix[i+1][l] = k * IdentityMatrix[i+1][l] - IdentityMatrix[j][l];
                }
                pivot();
            }
        }

        for(int j = 1; j < n; j++){
            for(int i = 0; i < n-1; i++){
                float k = 0;
                k = InputMatrix[i+1][j];
                for(int l = j; l < n; l++){
                    InputMatrix[i][l] -= k * InputMatrix[i][l];
                    IdentityMatrix[i][l] -= k * IdentityMatrix[i][l];
                }
            }
        }

        printf("\ninverse matrix\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("arr[%d][%d] : %.3f  ", i+1, j+1, IdentityMatrix[i][j]);
            }
            printf("\n");
        }
    }
                
};

int main(){
    Matrix matrix;
    matrix.SetN();
    matrix.initMatrix();
    matrix.SetInputMatrix();
    matrix.InverseMat();
    std::cout << "Sequece : return"<< std::endl;
    delete matrix.InputMatrix;
    delete matrix.IdentityMatrix;

    return 0;
}
