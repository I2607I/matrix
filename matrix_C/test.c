#include <check.h>
#include "matrix.h"


START_TEST(s21_create_matrix_test) {
    matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_remove_matrix_test) {
    matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test) {
    matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 1;
    int i = s21_eq_matrix(&A, &B);
    ck_assert_msg(i, "FAIL eq matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

    // matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 55;
    i = s21_eq_matrix(&A, &B);
    ck_assert_msg(!i, "FAIL eq matrix 2");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

    // matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    A.matrix[0][0] = 0.123456;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1234.0543;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 999999999;
    B.matrix[0][0] = 0.123456;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1234.0543;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 999999999;
    i = s21_eq_matrix(&A, &B);
    ck_assert_msg(i, "FAILED eq matrix 3");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

    // matrix_t A, B;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    A.matrix[0][0] = 0.123456;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1234.0543;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 234325.53;
    A.matrix[2][1] = 999999999;
    B.matrix[0][0] = 0.123456;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1234.0543;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 999999999;
    i = s21_eq_matrix(&A, &B);
    ck_assert_msg(!i, "FAIL eq matrix 4");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test) {
    matrix_t A, B, C, D;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    D = s21_create_matrix(3, 2);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 1;
    C = s21_sum_matrix(&A, &B);
    D.matrix[0][0] = 2;
    D.matrix[0][1] = 4;
    D.matrix[1][0] = 2;
    D.matrix[1][1] = 2;
    D.matrix[2][0] = 2;
    D.matrix[2][1] = 2;
    int i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sum matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

    // matrix_t A, B, C, D;
    A = s21_create_matrix(3, 3);
    B = s21_create_matrix(3, 3);
    D = s21_create_matrix(3, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 546.546;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[1][2] = 9999999.123456;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    A.matrix[2][2] = 0.2607;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[0][2] = 983.563;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[1][2] = 11111.11;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 1;
    B.matrix[2][2] = 0;
    C = s21_sum_matrix(&A, &B);
    D.matrix[0][0] = 2;
    D.matrix[0][1] = 4;
    D.matrix[0][2] = 1530.109;
    D.matrix[1][0] = 2;
    D.matrix[1][1] = 2;
    D.matrix[1][2] = 10011110.233456;
    D.matrix[2][0] = 2;
    D.matrix[2][1] = 2;
    D.matrix[2][2] = 0.2607;
    i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sum matrix 2");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

    // matrix_t A, B, C, D;
    A = s21_create_matrix(1, 1);
    B = s21_create_matrix(1, 1);
    D = s21_create_matrix(1, 1);
    A.matrix[0][0] = 1.23;
    B.matrix[0][0] = -1.15;
    C = s21_sum_matrix(&A, &B);
    D.matrix[0][0] = 0.08;
    i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sum matrix 3");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_sub_matrix_test) {
    matrix_t A, B, C, D;
    A = s21_create_matrix(3, 2);
    B = s21_create_matrix(3, 2);
    D = s21_create_matrix(3, 2);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 1;
    C = s21_sub_matrix(&A, &B);
    D.matrix[0][0] = 0;
    D.matrix[0][1] = 0;
    D.matrix[1][0] = 0;
    D.matrix[1][1] = 0;
    D.matrix[2][0] = 0;
    D.matrix[2][1] = 0;
    int i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sub matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

    //  matrix_t A, B, C, D;
    A = s21_create_matrix(3, 3);
    B = s21_create_matrix(3, 3);
    D = s21_create_matrix(3, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 546.546;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 1;
    A.matrix[1][2] = 9999999.123456;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 1;
    A.matrix[2][2] = 0.2607;
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[0][2] = 983.563;
    B.matrix[1][0] = 1;
    B.matrix[1][1] = 1;
    B.matrix[1][2] = 11111.11;
    B.matrix[2][0] = 1;
    B.matrix[2][1] = 6;
    B.matrix[2][2] = 0;
    C = s21_sub_matrix(&A, &B);
    D.matrix[0][0] = 0;
    D.matrix[0][1] = 0;
    D.matrix[0][2] = -437.017;
    D.matrix[1][0] = 0;
    D.matrix[1][1] = 0;
    D.matrix[1][2] = 9988888.013456;
    D.matrix[2][0] = 0;
    D.matrix[2][1] = -5;
    D.matrix[2][2] = 0.2607;
    i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sub matrix 2");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

    //  matrix_t A, B, C, D;
    A = s21_create_matrix(1, 1);
    B = s21_create_matrix(1, 1);
    D = s21_create_matrix(1, 1);
    A.matrix[0][0] = 1.23;
    B.matrix[0][0] = -1.15;
    C = s21_sub_matrix(&A, &B);
    D.matrix[0][0] = 2.38;
    i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL sub matrix 3");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_mult_number_test) {
    matrix_t A, B, C;
    A = s21_create_matrix(1, 1);
    B = s21_create_matrix(1, 1);
    A.matrix[0][0] = 5;
    double n = -6;
    C = s21_mult_number(&A, n);
    B.matrix[0][0] = -30;
    int i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL mult number 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    //  matrix_t A, B, C;
    A = s21_create_matrix(2, 3);
    B = s21_create_matrix(2, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 4;
    A.matrix[1][1] = 0;
    A.matrix[1][2] = 7.5;

    n = 2.5;
    C = s21_mult_number(&A, n);
    B.matrix[0][0] = 2.5;
    B.matrix[0][1] = 5;
    B.matrix[0][2] = 7.5;
    B.matrix[1][0] = 10;
    B.matrix[1][1] = 0;
    B.matrix[1][2] = 18.75;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL mult number 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test) {
    matrix_t A, B, C, D;
    A = s21_create_matrix(1, 1);
    B = s21_create_matrix(1, 1);
    D = s21_create_matrix(1, 1);
    A.matrix[0][0] = 5;
    B.matrix[0][0] = -6;
    C = s21_mult_matrix(&A, &B);
    D.matrix[0][0] = -30;
    int i = s21_eq_matrix(&C, &D);
    ck_assert_msg(i, "FAIL mult matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

    // matrix_t A, B, C, D;
    matrix_t CC, DD, AA, BB;
    AA = s21_create_matrix(3, 2);
    BB = s21_create_matrix(2, 3);
    DD = s21_create_matrix(3, 3);
    AA.matrix[0][0] = 1;
    AA.matrix[0][1] = 2;
    AA.matrix[1][0] = 1;
    AA.matrix[1][1] = 4;
    AA.matrix[2][0] = -2;
    AA.matrix[2][1] = 1;
    BB.matrix[0][0] = 1;
    BB.matrix[0][1] = 2;
    BB.matrix[0][2] = 3;
    BB.matrix[1][0] = 4;
    BB.matrix[1][1] = 0;
    BB.matrix[1][2] = 7.5;
    CC = s21_mult_matrix(&AA, &BB);
    DD.matrix[0][0] = 9;
    DD.matrix[0][1] = 2;
    DD.matrix[0][2] = 18;
    DD.matrix[1][0] = 17;
    DD.matrix[1][1] = 2;
    DD.matrix[1][2] = 33;
    DD.matrix[2][0] = 2;
    DD.matrix[2][1] = -4;
    DD.matrix[2][2] = 1.5;
    i = s21_eq_matrix(&CC, &DD);
    ck_assert_msg(i, "FAIL mult matrix 2");
    s21_remove_matrix(&AA);
    s21_remove_matrix(&BB);
    s21_remove_matrix(&CC);
    s21_remove_matrix(&DD);


    matrix_t CCCC, AAAA, BBBB, DDDD;
    AAAA = s21_create_matrix(1, 1);
    BBBB = s21_create_matrix(1, 1);
    DDDD = s21_create_matrix(1, 1);
    AAAA.matrix[0][0] = 5;
    BBBB.matrix[0][0] = -6;
    CCCC = s21_mult_matrix(&AAAA, &BBBB);
    DDDD.matrix[0][0] = -30;
    i = s21_eq_matrix(&CCCC, &DDDD);
    ck_assert_msg(i, "FAIL mult matrix 3");
    s21_remove_matrix(&AAAA);
    s21_remove_matrix(&BBBB);
    s21_remove_matrix(&CCCC);
    s21_remove_matrix(&DDDD);

    // matrix_t A, B, C, D;
    // matrix_t CC, DD, AA, BB;
    AA = s21_create_matrix(3, 2);
    BB = s21_create_matrix(2, 3);
    DD = s21_create_matrix(2, 2);
    AA.matrix[0][0] = 1;
    AA.matrix[0][1] = 2;
    AA.matrix[1][0] = 1;
    AA.matrix[1][1] = 4;
    AA.matrix[2][0] = -2;
    AA.matrix[2][1] = 1;
    BB.matrix[0][0] = 1;
    BB.matrix[0][1] = 2;
    BB.matrix[0][2] = 3;
    BB.matrix[1][0] = 4;
    BB.matrix[1][1] = 0;
    BB.matrix[1][2] = 7.5;
    CC = s21_mult_matrix(&BB, &AA);
    DD.matrix[0][0] = -3;
    DD.matrix[0][1] = 13;
    DD.matrix[1][0] = -11;
    DD.matrix[1][1] = 15.5;
    i = s21_eq_matrix(&CC, &DD);
    ck_assert_msg(i, "FAIL mult matrix 4");
    s21_remove_matrix(&AA);
    s21_remove_matrix(&BB);
    s21_remove_matrix(&CC);
    s21_remove_matrix(&DD);
}
END_TEST

START_TEST(s21_transpose_test) {
    matrix_t A, B, C;
    A = s21_create_matrix(1, 1);
    C = s21_create_matrix(1, 1);
    A.matrix[0][0] = 5;
    B = s21_transpose(&A);
    C.matrix[0][0] = 5;
    int i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL transpose matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    // matrix_t A, B, C;
    A = s21_create_matrix(3, 3);
    C = s21_create_matrix(3, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 546.546;
    A.matrix[1][0] = -1;
    A.matrix[1][1] = 1;
    A.matrix[1][2] = 9999999.123456;
    A.matrix[2][0] = 65.9;
    A.matrix[2][1] = 1;
    A.matrix[2][2] = 0.2607;
    B = s21_transpose(&A);
    C.matrix[0][0] = 1;
    C.matrix[0][1] = -1;
    C.matrix[0][2] = 65.9;
    C.matrix[1][0] = 2;
    C.matrix[1][1] = 1;
    C.matrix[1][2] = 1;
    C.matrix[2][0] = 546.546;
    C.matrix[2][1] = 9999999.123456;
    C.matrix[2][2] = 0.2607;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL transpose matrix 2");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test) {
    matrix_t A, B, C;
    A = s21_create_matrix(3, 3);
    C = s21_create_matrix(3, 3);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 6;
    A.matrix[0][2] = 5;
    A.matrix[1][0] = -1;
    A.matrix[1][1] = 9;
    A.matrix[1][2] = 8;
    A.matrix[2][0] = 8;
    A.matrix[2][1] = 0;
    A.matrix[2][2] = 2;
    B = s21_calc_complements(&A);
    C.matrix[0][0] = 18;
    C.matrix[0][1] = 66;
    C.matrix[0][2] = -72;
    C.matrix[1][0] = -12;
    C.matrix[1][1] = -36;
    C.matrix[1][2] = 48;
    C.matrix[2][0] = 3;
    C.matrix[2][1] = -21;
    C.matrix[2][2] = 24;
    int i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL compemtnt matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    A = s21_create_matrix(3, 3);
    C = s21_create_matrix(3, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;
    B = s21_calc_complements(&A);
    C.matrix[0][0] = 0;
    C.matrix[0][1] = 10;
    C.matrix[0][2] = -20;
    C.matrix[1][0] = 4;
    C.matrix[1][1] = -14;
    C.matrix[1][2] = 8;
    C.matrix[2][0] = -8;
    C.matrix[2][1] = -2;
    C.matrix[2][2] = 4;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL compemtnt matrix 2");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    A = s21_create_matrix(1, 1);
    C = s21_create_matrix(1, 1);
    A.matrix[0][0] = 1;
    B = s21_calc_complements(&A);
    C.matrix[0][0] = 1;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL compemtnt matrix 3");

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_determinant_test) {
    matrix_t A;
    A = s21_create_matrix(3, 3);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 6;
    A.matrix[0][2] = 5;
    A.matrix[1][0] = -1;
    A.matrix[1][1] = 9;
    A.matrix[1][2] = 8;
    A.matrix[2][0] = 8;
    A.matrix[2][1] = 0;
    A.matrix[2][2] = 2;
    double d = s21_determinant(&A);
    double D = 72;
    int i = eq_number(d, D);
    ck_assert_msg(i, "FAIL determinant matrix 1");
    s21_remove_matrix(&A);

    A = s21_create_matrix(3, 3);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 4;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 6;
    A.matrix[2][0] = 7;
    A.matrix[2][1] = 8;
    A.matrix[2][2] = 9;
    d = s21_determinant(&A);
    D = 0;
    i = eq_number(d, D);
    ck_assert_msg(i, "FAIL determinant matrix 2");
    s21_remove_matrix(&A);

    A = s21_create_matrix(2, 2);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;
    d = s21_determinant(&A);
    D = -2;
    i = eq_number(d, D);
    ck_assert_msg(i, "FAIL determinant matrix 3");
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
    matrix_t A, B, C;
    A = s21_create_matrix(3, 3);
    C = s21_create_matrix(3, 3);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 6;
    A.matrix[0][2] = 5;
    A.matrix[1][0] = -1;
    A.matrix[1][1] = 9;
    A.matrix[1][2] = 8;
    A.matrix[2][0] = 8;
    A.matrix[2][1] = 0;
    A.matrix[2][2] = 2;
    B = s21_inverse_matrix(&A);
    C.matrix[0][0] = (double)18/72;
    C.matrix[0][1] = (double)-12/72;
    C.matrix[0][2] = (double)3/72;
    C.matrix[1][0] = (double)66/72;
    C.matrix[1][1] = (double)-36/72;
    C.matrix[1][2] = (double)-21/72;
    C.matrix[2][0] = (double)-72/72;
    C.matrix[2][1] = (double)48/72;
    C.matrix[2][2] = (double)24/72;
    int i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL inverse matrix 1");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    A = s21_create_matrix(1, 1);
    C = s21_create_matrix(1, 1);
    A.matrix[0][0] = 2;
    B = s21_inverse_matrix(&A);
    C.matrix[0][0] = 0.5;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL inverse matrix 2");

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);

    A = s21_create_matrix(1, 1);
    C = s21_create_matrix(1, 1);
    A.matrix[0][0] = 1;
    B = s21_inverse_matrix(&A);
    C.matrix[0][0] = 1;
    i = s21_eq_matrix(&C, &B);
    ck_assert_msg(i, "FAIL inverse matrix 3");

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST



Suite *s21_string_suite(void) {
    Suite *suite;
    TCase *getCase;

    suite = suite_create("String");
    getCase = tcase_create("core");

    tcase_add_test(getCase, s21_create_matrix_test);
    tcase_add_test(getCase, s21_remove_matrix_test);
    tcase_add_test(getCase, s21_eq_matrix_test);
    tcase_add_test(getCase, s21_sum_matrix_test);
    tcase_add_test(getCase, s21_sub_matrix_test);
    tcase_add_test(getCase, s21_mult_number_test);
    tcase_add_test(getCase, s21_mult_matrix_test);
    tcase_add_test(getCase, s21_transpose_test);
    tcase_add_test(getCase, s21_calc_complements_test);
    tcase_add_test(getCase, s21_determinant_test);
    tcase_add_test(getCase, s21_inverse_matrix_test);
    suite_add_tcase(suite, getCase);

    return suite;
}

int main(void) {
    int amountOfFailed = 0;
    Suite *suite;
    SRunner *runner;

    suite = s21_string_suite();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    amountOfFailed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (amountOfFailed == 0) ? 0 : 1;
}
