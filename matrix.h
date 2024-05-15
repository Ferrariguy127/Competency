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
double GetElementrow(Matrix *new_matrix, int row);
double GetElementCol(Matrix *new_matrix, int col);
double NewRowValues(Matrix *new_matrix, int row, double values);
double NewColValues(Matrix *new_matrix, int col, double values);
void freeMatrix(Matrix* m);
#endif