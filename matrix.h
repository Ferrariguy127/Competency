#ifndef matrix_h
#define matrix_h

struct Matrix 
{
    int width;
    int height;
    double **two_dimension_array;
};

typedef struct Matrix Matrix;
Matrix* matrix_initilization(int width, int height, double array[width][height]);
void print_matrix(Matrix* matrix);

double getMatrixElement(const Matrix* m, int row, int col);

void freeMatrix(Matrix* m);
#endif