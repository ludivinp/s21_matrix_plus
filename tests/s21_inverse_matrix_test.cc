#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_00) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW(matrix.InverseMatrix());
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_01) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW(matrix.InverseMatrix());
}
TEST(S21MatrixInverseMatrix, InverseMatrixFunc_02) {
  S21Matrix matrix{2, 3};

  ASSERT_ANY_THROW(matrix.InverseMatrix());
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_03) {
  S21Matrix matrix{10, 5};

  ASSERT_ANY_THROW(matrix.InverseMatrix());
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_04) {
  S21Matrix matrix{10, 10};

  ASSERT_ANY_THROW(matrix.InverseMatrix());
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_05) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 123;
  matrix(0, 1) = 987;
  matrix(1, 0) = 12;
  matrix(1, 1) = 98;

  const S21Matrix &&matrix_result = matrix.InverseMatrix();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_TRUE(abs(matrix_result(0, 0) - 0.466666667) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 1) - -4.7) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 0) - -0.057142857) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 1) - 0.585714286) < matrix_result.kEpsilon);
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_06) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 1.2345;
  matrix(0, 1) = 0.12345;
  matrix(1, 0) = 123.45;
  matrix(1, 1) = 12345;

  const S21Matrix &&matrix_result = matrix.InverseMatrix();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_TRUE(abs(matrix_result(0, 0) - 0.810855408) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 1) - -0.000008109) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 0) - -0.008108554) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 1) - 0.000081086) < matrix_result.kEpsilon);
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_07) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = -1.2;
  matrix(0, 1) = 34.5;
  matrix(1, 0) = 987;
  matrix(1, 1) = -65.4;

  const S21Matrix &&matrix_result = matrix.InverseMatrix();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_TRUE(abs(matrix_result(0, 0) - 0.001925057) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 1) - 0.001015512) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 0) - 0.029052466) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 1) - 0.000035322) < matrix_result.kEpsilon);
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_08) {
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

  const S21Matrix &&matrix_result = matrix.InverseMatrix();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_TRUE(abs(matrix_result(0, 0) - -0.000254155) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 1) - 0.001247347) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 2) - -0.00016197) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 0) - -0.000360127) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 1) - -0.000360127) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 2) - 0.000323939) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 0) - 0.001515182) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 1) - 0.000013681) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 2) - -0.00016197) < matrix_result.kEpsilon);
}

TEST(S21MatrixInverseMatrix, InverseMatrixFunc_09) {
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

  const S21Matrix &&matrix_result = matrix.InverseMatrix();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_TRUE(abs(matrix_result(0, 0) - 0.087826744) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 1) - -0.260613484) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(0, 2) - 0.008079018) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 0) - 0.267128821) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 1) - 0.208816554) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(1, 2) - 0.006026687) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 0) - 0.001693988) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 1) - 0.013519324) < matrix_result.kEpsilon);
  EXPECT_TRUE(abs(matrix_result(2, 2) - 0.018330901) < matrix_result.kEpsilon);
}
