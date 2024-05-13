#ifndef matrix_h
#define matrix_h

struct Matrix 
{
    int height;
    int width;
    double **two_dimension_array;
};

typedef struct Matrix Matrix;
Matrix* matrix_initilization(int height, int width, double array[height][width]);
void print_matrix(Matrix* matrix);

#endif