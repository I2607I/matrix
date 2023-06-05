#include "matrix.h"

matrix_t s21_create_matrix(int rows, int columns) {
    matrix_t A;
    A.rows = rows;
    A.columns = columns;
    A.matrix_type = ZERO_MATRIX;
    A.matrix = malloc(rows*sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        A.matrix[i] = malloc(columns*sizeof(double));
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            A.matrix[i][j] = 0;
        }
    }
    return A;
}

void s21_remove_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; ++i)
    if (A->matrix[i] != NULL) free(A->matrix[i]);
    if (A->matrix != NULL) free(A->matrix);
}


int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int returnable = 0;
    if (A->matrix_type != 1 && B->matrix_type !=1 && A->columns == B->columns && A->rows == B->rows) {
        int res = 1;
        for (int i = 0; i < A->rows; ++i) {
            for (int j =0; j < A->columns; ++j) {
                res*=eq_number(A->matrix[i][j], B->matrix[i][j]);
            }
        }
        returnable = res;
    }
    return returnable;
}

int eq_number(double a, double b) {
    int returnable = 0;
    double E = 0.0000001;
    if (fabs(a - b) < E)
        returnable = 1;
    return returnable;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t C = s21_create_matrix(A->rows, A->columns);
    C.matrix_type = 1;
    if (A->matrix_type != 1 && B->matrix_type !=1 && A->columns == B->columns && A->rows == B->rows) {
        for (int i = 0; i < A->rows; ++i) {
            for (int j =0; j < A->columns; ++j) {
                C.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    matrix_t C = s21_create_matrix(A->rows, A->columns);
    C.matrix_type = 1;
    if (A->matrix_type != 1 && B->matrix_type !=1 && A->columns == B->columns && A->rows == B->rows) {
        for (int i = 0; i < A->rows; ++i) {
            for (int j =0; j < A->columns; ++j) {
                C.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    matrix_t C = s21_create_matrix(A->rows, A->columns);
    C.matrix_type = 1;
    if (A->matrix_type !=1) {
        for (int i = 0; i < A->rows; ++i) {
            for (int j =0; j < A->columns; ++j) {
                C.matrix[i][j] = A->matrix[i][j]*number;
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t C = s21_create_matrix(A->rows, B->columns);
    C.matrix_type = 1;
    if (A->matrix_type != 1 && B->matrix_type != 1 && A->columns == B->rows) {
        for (int i = 0; i < A->rows; ++i) {
            for (int j =0; j < B->columns; ++j) {
                for (int k = 0; k < A->columns; k++) {
                    C.matrix[i][j] += A->matrix[i][k]*B->matrix[k][j];
                }
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

matrix_t s21_transpose(matrix_t *A) {
    matrix_t C = s21_create_matrix(A->columns, A->rows);
    C.matrix_type = 1;
    if (A->matrix_type !=1) {
        for (int i = 0; i < A->columns; ++i) {
            for (int j =0; j < A->rows; ++j) {
                C.matrix[i][j] = A->matrix[j][i];
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

matrix_t s21_calc_complements(matrix_t *A) {
    matrix_t C = s21_create_matrix(A->columns, A->rows);
    C.matrix_type = 1;
    if (A->matrix_type != 1 && A->rows == A->columns) {
        int n = A->rows;
        if (n == 1) {
            C.matrix[0][0] = A->matrix[0][0];
        } else if (n > 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (n > 1) {
                        matrix_t M = minorr(A, i, j);
                        C.matrix[i][j] = pow(-1, i+j)*s21_determinant(&M);
                        s21_remove_matrix(&M);
                    }
                }
            }
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

double s21_determinant(matrix_t *A) {
    double returnable = 0.0/0.0;
    if (A->matrix_type !=1 && A->columns == A->rows) {
        if (A->rows == 1) {
            returnable = A->matrix[0][0];
        } else if (A->rows == 2) {
            returnable = A->matrix[0][0]*A->matrix[1][1] - A->matrix[0][1]*A->matrix[1][0];
        } else {
            double res = 0;
            for (int i = 0; i < A->rows; ++i) {
                matrix_t M = minorr(A, 0, i);
                res += A->matrix[0][i]*s21_determinant(&M)*pow(-1, i);
                s21_remove_matrix(&M);
            }
            returnable = res;
        }
    }
    return returnable;
}

matrix_t minorr(matrix_t *A, int i, int j) {
    matrix_t C = s21_create_matrix(A->columns - 1, A->rows - 1);
    int n = A->rows;
    for (int ii = 0; ii < n - 1; ii++) {
        for (int jj = 0; jj < n - 1; jj++) {
            if (ii < i && jj < j)
                    C.matrix[ii][jj] = A->matrix[ii][jj];
            if (ii < i && jj >= j)
                    C.matrix[ii][jj] = A->matrix[ii][jj+1];
            if (ii >= i && jj < j)
                    C.matrix[ii][jj] = A->matrix[ii+1][jj];
            if (ii >= i && jj >= j)
                    C.matrix[ii][jj] = A->matrix[ii+1][jj+1];
        }
    }
    C.matrix_type = 0;
    return C;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    matrix_t C = s21_create_matrix(A->rows, A->columns);
    C.matrix_type = 1;
    double d = s21_determinant(A);
    if (A->matrix_type != 1 && A->rows == A->columns && fabs(d) > 0.0000001) {
        if (A->rows == 1) {
            C.matrix[0][0] = 1/A->matrix[0][0];
        } else {
            matrix_t M, C1;
            s21_remove_matrix(&C);
            M = s21_calc_complements(A);
            C1 = s21_transpose(&M);
            s21_remove_matrix(&M);
            C = s21_mult_number(&C1, 1/d);
            s21_remove_matrix(&C1);
        }
        C.matrix_type = 0;
    }
    check_type(&C);
    return C;
}

void check_type(matrix_t *A) {
    if (A->matrix_type == 0) {
        int flag_zero = 0;
        int flag_one = 0;
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (A->matrix[i][j] != 0) {
                    flag_zero = 1;
                    break;
                }
            }
            if (flag_zero != 0) break;
        }
        if (flag_zero == 0) {
            A->matrix_type = ZERO_MATRIX;
        }
        if (A->columns == A->rows) {
            int n = A->columns;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && A->matrix[i][j] != 0) {
                        flag_one = 1;
                        break;
                    }
                    if (i == j && A->matrix[i][i] != 1) {
                        flag_one = 1;
                        break;
                    }
                }
                if (flag_one == 1) break;
            }
            if (flag_one == 0) {
            A->matrix_type = IDENTITY_MATRIX;
            }
        }
    }
}

