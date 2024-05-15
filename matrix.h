#ifndef matrix_h
#define matrix_h

struct Matrix 
{
    int row;
    int col;
    double **data;
};

typedef struct Matrix Matrix;
Matrix* matrix_initilization(int rows, int columns);
void FillMatrixData(Matrix *new_matrix, double data[][new_matrix->col]);
void print_matrix(Matrix* matrix);

double getMatrixElement(const Matrix* m, int row, int col);

void freeMatrix(Matrix* m);
#endif