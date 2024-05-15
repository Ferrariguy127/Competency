#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./matrix.h"

int main(void)
{
  //This function is where the user or developer will adjust the size of the matrix and the values used
  double matrix_array1[3][3] = {
    {4, 3, 1},
    {3, 3, 1},
    {4, 2, 4}
  };
  double matrix_array2[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {1, 2, 3}
  };
  
  Matrix *matrix = matrix_initilization(3, 3);
  FillMatrixData(matrix, matrix_array1);
  print_matrix(matrix);
  printf("\n");
  Matrix *matrix2 = matrix_initilization(4, 3);
  FillMatrixData(matrix2, matrix_array2);
  print_matrix(matrix2);

  //Function for getting value at set position
  printf("Element at (1,1): %.2f\n", getMatrixElement(matrix, 1, 1));

  //Function for getting the value at a given Row
  printf("\n", GetElementrow(matrix, 1));
  
  //Function to get the value at a given Column
  printf("\n", GetElementCol(matrix, 1));


//Matrix addition function call

//matrix subtraction function call

//matrix multiplication function call

//matrix rotation function call



  freeMatrix(matrix);
  freeMatrix(matrix2);

}
