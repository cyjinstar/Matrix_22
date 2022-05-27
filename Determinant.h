#ifndef __DETERMINANT_H__
#define __DETERMINANT_H__

#include <iostream>

using namespace std;

class DetClass {
   public:
    float **submatrix(float **matrix, int n, int x, int y);
    float determinant(float **matrix, int n);
    float **detInvese(float **matrix, int n);
};

#endif