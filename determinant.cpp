#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Determinant.h"

using namespace std;

 int** DetClass::submatrix(int **matrix, unsigned int n, unsigned int x, unsigned int y) {
     int **submatrix = new int *[n - 1];
     int subi = 0;
     for (int i = 0; i < n; i++) {
         submatrix[subi] = new int[n - 1];
         int subj = 0;
         if (i == y) {
             continue;
         }
         for (int j = 0; j < n; j++) {
             if (j == x) {
                 continue;
             }
             submatrix[subi][subj] = matrix[i][j];
             subj++;
         }
         subi++;
     }
     return submatrix;
 }

 int DetClass::determinant(int **matrix, unsigned int n) {
     int det = 0;
     if (n == 2) {
         return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
     }
     for (int x = 0; x < n; ++x) {
         det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
     }
     return det;
 }