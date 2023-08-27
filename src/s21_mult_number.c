#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (s21_check_order(A)) {
    if (s21_check_nan(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
    } else
      status = CALCULATING_ERROR;
  } else
    status = UNCORRECT_MATRIX;
  return status;
}