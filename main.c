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
  double matrix_array2[3][4] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {1, 2, 3}
  };
  
  Matrix* matrix = matrix_initilization(3, 3, matrix_array1);
  print_matrix(matrix);
  printf("\n");
  Matrix* matrix2 = matrix_initilization(3, 4, matrix_array2);
  print_matrix(matrix);

  //Function for getting value at set position
  printf("Element at (1,1): %.2f\n", getMatrixElement(matrix_array1, 1, 1));
  printf("This line works\n");
  freeMatrix(matrix_array1);

//Matrix addition function call

//matrix subtraction function call

//matrix multiplication function call

//matrix rotation function call


  return;
}
