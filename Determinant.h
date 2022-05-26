#ifndef __DETERMINANT_H__
#define __DETERMINANT_H__

#include <iostream>

using namespace std;

class DetClass {
   public:
    int **submatrix(int **matrix, unsigned int n, unsigned int x, unsigned int y);
    int determinant(int **matrix, unsigned int n);
};

#endif