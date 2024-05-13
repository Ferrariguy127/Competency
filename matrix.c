#include <stdio.h>

void help(int num){printf("This works %d\n", num);}
//This is a simple helper to help find where code is breaking and printing this works with the number associated with it.

struct Matrix 
{
    int height;
    int width;
    double **two_dimension_array;
};

typedef struct Matrix Matrix;

Matrix* matrix_initilization(int width,int height, double array[width][height])
{
    Matrix* new_matrix = (Matrix*)malloc(sizeof(Matrix));
    new_matrix->width = width;
    new_matrix->height = height;
    


    double **new_2d_array = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++)
    {
        double *new_array = (double*)malloc(width * sizeof(double));
        new_2d_array[i] = new_array;
        for (int j = 0; j < width; j++)
        {
            new_array[j] = array[i][j];
        }
    }

    new_matrix->two_dimension_array=new_2d_array;
    return new_matrix;
}
//Simply put this will take the matrix struct from above and print it out
void print_matrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < matrix->width; j++)
        {
            printf("%f, ", matrix->two_dimension_array[i][j]);
        }
        printf("\n");
    }
}
//I will always free memory I Malloc and I will only free Memory "I" malloc!
void freeMatrix(Matrix* m){
    if (m != NULL){
        //frees everything malloc'd
        for (int i=0; i<m->height; i++){
            free(m->two_dimension_array[i]);
        }
        //Free pointers
        free(m->two_dimension_array);
        free(m);
    }
}