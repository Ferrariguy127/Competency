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
        exit(1);
    }

    new_matrix->row = rows;
    new_matrix->col = columns;
    
    //Allocation system
    new_matrix->data = (double**)malloc(rows * sizeof(double*));
    if (new_matrix->data == NULL){
        printf("Matrix failed to allocate memory.\n");
        exit(1);
    }

    //Allocates pointers
    for (int i = 0; i < rows; i++){
        new_matrix->data[i] = (double*)malloc(columns * sizeof(double));
        if (new_matrix->data[i] == NULL){
            printf("Failed to allocate memory within Matrix.\n");
            exit(1);
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
double getMatrixElement(Matrix *new_matrix, int row, int col){
    if (new_matrix ==NULL){
        printf("This is null");
        exit(1);
    }

    //printf("row=%d, col=%d, row=%d", row, col, new_matrix->row, new_matrix->col);
    //this should get a debug flag on it later but need progress first.

    if (row < 0 || col < 0 || row >= new_matrix->row || col >= new_matrix->col){

            printf("This is out of range. row:%d, col:%d \n");
            return -1;
    }
        //printf("This has finished running \n");This was a test statement for debugging.
        return new_matrix->data[row][col];
    

}

//This should be able to pull the values of a single element in the matrix
double GetElementrow(Matrix *new_matrix, int row){
    if (new_matrix==NULL || row < 0 || row >= new_matrix->row){
        printf("This row does not exist within these bounds");
        exit(1);
    }
    printf("The elements found in row  are:");
    for (int j=0; j < new_matrix->col; j++){
        printf(" %.2f\t",new_matrix->data[row][j]);
    }
}
//This should be able to pull the values from a single column in the matrix
double GetElementCol(Matrix *new_matrix, int col){
    if (new_matrix==NULL || col < 0|| col >= new_matrix->col){
        printf("This input is not in the bounds of this matrix");
        exit(1);
    }
    printf("The elements in that column are: ");
    for (int i=0; i< new_matrix->row; i++){
        printf("%.2f\t", new_matrix->data[i][col]);
    }
}
//This shouuld fill the values in a given row to be that of the input
double NewRowValues(Matrix *new_matrix, int row, double values){
    if (new_matrix==NULL || row < 0 || row>= new_matrix->row){
        printf("This didn't work due to improper bounds.");
        exit(1);
        }
        printf("New row down as follows\n");
        for(int j=0; j<new_matrix->row; j++){
            new_matrix->data[row][j] = values;
            printf("%.2f\t", new_matrix->data[row][j]);
        }//Note the position of [row][j], if swapped it runs similar to [i][col]
        printf("\n");
    }
//This is the Column value swapping funciton
double NewColValues(Matrix *new_matrix, int col, double values){
    if (new_matrix==NULL || col<0 || col>= new_matrix->col){
        printf("The selected input is outside this programs bounds");
        exit(1);
    }
    printf("New Column as follows\n");
    for (int i=0; i<new_matrix->col; i++){
        new_matrix->data[i][col]=values;
        printf("%.2f\n", new_matrix->data[i][col]);
    }
    printf("\n");
}

//Create a matrix from a given matrix (Subset)
double **extractSubset(double **nm, int startRow, int startCol, int targetRow, int targetCol){
    double **dest = (double **)malloc(targetRow * sizeof(double *));
    if(!dest) return NULL; //should see if malloc fails and exit


    for (int i=0; i< targetRow; i++){
        dest[i] = (double *)malloc(targetCol * sizeof(double));
        if (!dest[i]){
            for (int j =0; j<i; j++){
                free(dest[j]);
            }
            free(dest);
            return NULL;
        }
    }

    //Copy the values for the new matrix
    for (int i =0; i<targetRow; i++){
        for (int j=0; j<targetCol; j++){
            dest[i][j] = nm[startRow+i][startCol+j];
        }
    }
    return dest;
}
void printSubset(double **matrix, int row, int col){
    for (int i=0; i< row; i++){
        for(int j=0; j<col; j++){
        printf("This is the new subset");
        printf("%f", matrix[i][j]);
        }
        printf("\n");
    }
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