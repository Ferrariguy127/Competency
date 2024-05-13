#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./matrix.h"

int main(void)
{
  double matrix_array[2][3] = {
    {2, 2, 1},
    {3, 3, 1}
  };
  
  Matrix* matrix = matrix_initilization(2, 3, matrix_array);
  print_matrix(matrix);

  return 0;
}
