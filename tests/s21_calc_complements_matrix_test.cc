#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixCalcComplements, CalcComplementsFunc_00) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW(matrix.CalcComplements());
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_01) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW(matrix.CalcComplements());
}
TEST(S21MatrixCalcComplements, CalcComplementsFunc_02) {
  S21Matrix matrix{2, 3};

  ASSERT_ANY_THROW(matrix.CalcComplements());
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_03) {
  S21Matrix matrix{10, 5};

  ASSERT_ANY_THROW(matrix.CalcComplements());
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_04) {
  S21Matrix matrix{10, 10};

  ASSERT_NO_THROW(matrix.CalcComplements());
}
TEST(S21MatrixCalcComplements, CalcComplementsFunc_05) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 0;
  matrix(0, 1) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 0;

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 0);
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_06) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 123;
  matrix(0, 1) = 987;
  matrix(1, 0) = 12;
  matrix(1, 1) = 98;

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 98);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), -12);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), -987);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 123);
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_07) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = 1.2345;
  matrix(0, 1) = 0.12345;
  matrix(1, 0) = 123.45;
  matrix(1, 1) = 12345;

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 12345);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), -123.45);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), -0.12345);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 1.2345);
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_08) {
  S21Matrix matrix{2, 2};

  matrix(0, 0) = -1.2;
  matrix(0, 1) = 34.5;
  matrix(1, 0) = 987;
  matrix(1, 1) = -65.4;

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), -65.4);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), -987);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), -34.5);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), -1.2);
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_09) {
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

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), -580005);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), -821844);
  EXPECT_DOUBLE_EQ(matrix_result(0, 2), 3457791);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 2846565);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), -821844);
  EXPECT_DOUBLE_EQ(matrix_result(1, 2), 31221);
  EXPECT_DOUBLE_EQ(matrix_result(2, 0), -369630);
  EXPECT_DOUBLE_EQ(matrix_result(2, 1), 739260);
  EXPECT_DOUBLE_EQ(matrix_result(2, 2), -369630);
}

TEST(S21MatrixCalcComplements, CalcComplementsFunc_10) {
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

  const S21Matrix &&matrix_result = matrix.CalcComplements();

  EXPECT_EQ(matrix.GetRows(), matrix_result.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_result.GetCols());

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 53.92);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 164);
  EXPECT_DOUBLE_EQ(matrix_result(0, 2), 1.04);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), -160);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 128.2);
  EXPECT_DOUBLE_EQ(matrix_result(1, 2), 8.3);
  EXPECT_DOUBLE_EQ(matrix_result(2, 0), 4.96);
  EXPECT_DOUBLE_EQ(matrix_result(2, 1), 3.7);
  EXPECT_DOUBLE_EQ(matrix_result(2, 2), 11.254);
}
