#include <stdio.h>

void help(int num){printf("This works %d\n", num);}

struct Matrix 
{
    int height;
    int width;
    double **two_dimension_array;
};

typedef struct Matrix Matrix;

Matrix* matrix_initilization(int height, int width, double array[height][width])
{
    Matrix* new_matrix = (Matrix*)malloc(sizeof(Matrix));
    new_matrix->height = height;
    new_matrix->width = width;


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