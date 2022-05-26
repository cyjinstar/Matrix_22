#ifndef __DETERMINANT_H__
#define __DETERMINANT_H__

#include <iostream>

using namespace std;

class DetClass {
   public:
    float **submatrix(float **matrix, unsigned int n, unsigned int x, unsigned int y);
    int determinant(float **matrix, unsigned int n);
};

#endif