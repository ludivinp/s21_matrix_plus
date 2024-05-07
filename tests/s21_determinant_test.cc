#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixDeterminant, DeterminantFunc_00) {
  S21Matrix matrix{};

  ASSERT_NO_THROW(matrix.Determinant());
}

TEST(S21MatrixDeterminant, DeterminantFunc_01) {
  S21Matrix matrix{10, 10};

  ASSERT_NO_THROW(matrix.Determinant());
}

TEST(S21MatrixDeterminant, DeterminantFunc_02) {
  S21Matrix matrix{9, 10};

  ASSERT_ANY_THROW(matrix.Determinant());
}

TEST(S21MatrixDeterminant, DeterminantFunc_03) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 123.456);
}

TEST(S21MatrixDeterminant, DeterminantFunc_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = -1234567;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), -1234567);
}

TEST(S21MatrixDeterminant, DeterminantFunc_05) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 0;
  matrix(0, 1) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 0;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 0);
}

TEST(S21MatrixDeterminant, DeterminantFunc_06) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 123;
  matrix(0, 1) = 987;
  matrix(1, 0) = 12;
  matrix(1, 1) = 98;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 210);
}

TEST(S21MatrixDeterminant, DeterminantFunc_07) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 1.2345;
  matrix(0, 1) = 0.12345;
  matrix(1, 0) = 123.45;
  matrix(1, 1) = 12345;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 15224.6625975);
}

TEST(S21MatrixDeterminant, DeterminantFunc_08) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = -1.2;
  matrix(0, 1) = 34.5;
  matrix(1, 0) = 987;
  matrix(1, 1) = -65.4;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), -33973.02);
}

TEST(S21MatrixDeterminant, DeterminantFunc_09) {
  S21Matrix matrix{3, 3};

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 0);
}

TEST(S21MatrixDeterminant, DeterminantFunc_10) {
  S21Matrix matrix{3, 3};

  matrix(0, 0) = 123;
  matrix(0, 1) = 456;
  matrix(0, 2) = 789;
  matrix(1, 0) = 987;
  matrix(1, 1) = 654;
  matrix(1, 2) = 321;
  matrix(2, 0) = 1234;
  matrix(2, 1) = 4321;
  matrix(2, 2) = 1234;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 2282095620);
}

TEST(S21MatrixDeterminant, DeterminantFunc_11) {
  S21Matrix matrix{3, 3};

  matrix(0, 0) = 123;
  matrix(0, 1) = 456;
  matrix(0, 2) = 789;
  matrix(1, 0) = 987;
  matrix(1, 1) = 654;
  matrix(1, 2) = 321;
  matrix(2, 0) = 1234;
  matrix(2, 1) = 4321;
  matrix(2, 2) = 1234;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 2282095620);
}

TEST(S21MatrixDeterminant, DeterminantFunc_12) {
  S21Matrix matrix{3, 3};

  matrix(0, 0) = 2.3;
  matrix(0, 1) = 3;
  matrix(0, 2) = -2;
  matrix(1, 0) = -3;
  matrix(1, 1) = 0.98;
  matrix(1, 2) = 1;
  matrix(2, 0) = 2;
  matrix(2, 1) = -1;
  matrix(2, 2) = 54;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 613.936);
}

TEST(S21MatrixDeterminant, DeterminantFunc_13) {
  S21Matrix matrix{4, 4};

  matrix(0, 0) = -12.34;
  matrix(0, 1) = 1234;
  matrix(0, 2) = 12.34;
  matrix(0, 3) = -123;

  matrix(1, 0) = 98.7;
  matrix(1, 1) = 987.8;
  matrix(1, 2) = -987.65;
  matrix(1, 3) = 987.6;

  matrix(2, 0) = 1;
  matrix(2, 1) = 2;
  matrix(2, 2) = 3;
  matrix(2, 3) = 4;

  matrix(3, 0) = 9;
  matrix(3, 1) = 8;
  matrix(3, 2) = 7;
  matrix(3, 3) = 6;

  ASSERT_DOUBLE_EQ(matrix.Determinant(), 66385096.44);
}
