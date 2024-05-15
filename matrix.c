#include <stdio.h>

void help(int num){printf("This works %d\n", num);}
//This is a simple helper to help find where code is breaking and printing this works with the number associated with it.

struct Matrix 
{
    int row;
    int col;
    double **data;
};

typedef struct Matrix Matrix;

Matrix* matrix_initilization(int rows,int columns)
{
    Matrix *new_matrix = (Matrix*)malloc(sizeof(Matrix));

    if (new_matrix == NULL){
        printf("Matrix failed to initialize.\n");
    }

    new_matrix->row = rows;
    new_matrix->col = columns;
    
    //Allocation system
    new_matrix->data = (double**)malloc(rows * sizeof(double*));
    if (new_matrix->data == NULL){
        printf("Matrix failed to allocate memory.\n");
    }

    //Allocates pointers
    for (int i = 0; i < rows; i++){
        new_matrix->data[i] = (double*)malloc(columns * sizeof(double));
        if (new_matrix->data[i] == NULL){
            printf("Failed to allocate memory within Matrix.\n");
        }
    }
    return new_matrix;
}
void FillMatrixData(Matrix *new_matrix, double data[][new_matrix->col]){
    for (int i=0; i< new_matrix->row; i++){
        for (int j=0; j<new_matrix->col; j++){
            new_matrix->data[i][j]=data[i][j];
        }
    }
}
//Simply put this will take the matrix struct from above and print it out
void print_matrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%.2f, ", matrix->data[i][j]);//.2f only keeps 2 values after the .
        }
        printf("\n");
    }
}

//How to get the value from a given position of the arrary
double getMatrixElement(Matrix *m, int row, int col){
    if (m ==NULL){
        printf("This is null");
        return -2;
    }

    printf("row=%d, col=%d, row=%d", row, col, m->row, m->col);

    if (row < 0 || col < 0 || row >= m->row || col >= m->col){

            printf("This is out of range. row:%d, col:%d \n");
            return -1;
    }
        printf("This has finished running \n");
        return m->data[row][col];
    

}

//I will always free memory I Malloc and I will only free Memory "I" malloc!
void freeMatrix(Matrix *new_matrix){
    if (new_matrix->data != NULL) {
    //frees everything malloc'd
    for (int i=0; i<new_matrix->row; i++){        
        free(new_matrix->data[i]);
    }
    //Free pointers
    free(new_matrix->data);
    
        free(new_matrix);
        printf("Memory has been cleared.\n");
    }
}