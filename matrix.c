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
    new_matrix->height = height;
    new_matrix->width = width;
    


    double **new_2d_array = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++){

        new_2d_array[i] = (double*)malloc(width * sizeof(double));
            for (int j = 0; j < width; j++){
        new_2d_array[i][j] = array[i][j];
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
            printf("%.2f, ", matrix->two_dimension_array[i][j]);//.2f only keeps 2 values after the .
        }
        printf("\n");
    }
}

//How to get the value from a given position of the arrary
double getMatrixElement(Matrix* m, int row, int col){
    if (m ==NULL){
        printf("This is null");
        return -2;
    }

    printf("row=%d, col=%d, height=%d", row, col, m->height, m->width);
    
    if (row < 0 || col < 0 || row >= m->height || col >= m->width){

            printf("This is out of range. row: %d, col: %d \n");
            return -1;
    }
        printf("This has finished running \n");
        return m->two_dimension_array[row][col];
    

}

//I will always free memory I Malloc and I will only free Memory "I" malloc!
void freeMatrix(Matrix* m){
    if (m = NULL){
        help(1);
        return;
        
    }
    if (m->two_dimension_array != NULL) {
    //frees everything malloc'd
    help(3);
    for (int i=0; i<m->height; i++){
        if (m->two_dimension_array != NULL){
        help(4);
        free(m->two_dimension_array[i]);
        m->two_dimension_array[i] = NULL;
        }
        help(5);
    }
    //Free pointers
    free(m->two_dimension_array);
    }
        free(m);
    }