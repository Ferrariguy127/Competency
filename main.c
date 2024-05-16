#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./matrix.h"

int main(void)
{
  //This function is where the user or developer will adjust the size of the matrix and the values used
  double matrix_array1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  double matrix_array2[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {1, 2, 3}
  };
  double matrix_array3[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
  };

  
  Matrix *matrix = matrix_initilization(3, 3);
  FillMatrixData(matrix, matrix_array1);
  print_matrix(matrix);
  printf("\n");
  Matrix *matrix2 = matrix_initilization(4, 3);
  FillMatrixData(matrix2, matrix_array2);
  print_matrix(matrix2);
  printf("\n");
  Matrix *matrix3 = matrix_initilization(3, 3);
  FillMatrixData(matrix3, matrix_array3);
  print_matrix(matrix3);
  

  //Function for getting value at set position
  printf("Element at (1,1): %.2f\n", getMatrixElement(matrix, 1, 1));

  //Function for getting the value at a given Row
  printf("\n", GetElementrow(matrix, 1));
  
  //Function to get the value at a given Column
  printf("\n", GetElementCol(matrix, 1));

  //Function for Row Swapping:
  printf("",NewRowValues(matrix, 1, 1));

  //Funciton for Col Swapping:
  printf("", NewColValues(matrix2,1,1));

  //Function for matrix subset:
  double **sourceMatrix = matrix_initilization(4,4);
  if (sourceMatrix == NULL){
    printf("Failed to allocate properly and will now exit");
    exit(1);
  }

  printf(sourceMatrix);

//Matrix addition function call
  printf("", matrix_addition(matrix,matrix3));

//matrix subtraction function call
  printf("", matrix_subtraction(matrix,matrix3));
//matrix multiplication function call

//matrix rotation function call



  freeMatrix(matrix);
  freeMatrix(matrix2);
  freeMatrix(matrix3);
}
