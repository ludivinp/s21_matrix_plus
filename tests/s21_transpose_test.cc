#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixTranspose, TransposeFunc_00) {
  S21Matrix matrix{};

  ASSERT_NO_THROW(matrix.Transpose());
}

TEST(S21MatrixTranspose, TransposeFunc_01) {
  S21Matrix matrix{5, 10};

  ASSERT_NO_THROW(matrix.Transpose());
}

TEST(S21MatrixTranspose, TransposeFunc_02) {
  S21Matrix matrix{0, 0};

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 0);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixTranspose, TransposeFunc_03) {
  S21Matrix matrix{0, 1};

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixTranspose, TransposeFunc_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_result(0, 0), 123.456);
}

TEST(S21MatrixTranspose, TransposeFunc_05) {
  S21Matrix matrix{1, 2};

  matrix(0, 0) = 123.456;

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 2);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_result(0, 0), 123.456);
}

TEST(S21MatrixTranspose, TransposeFunc_06) {
  S21Matrix matrix{5, 5};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 5);
  EXPECT_EQ(matrix_result.GetCols(), 5);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j), matrix(j, i));
    }
  }
}

TEST(S21MatrixTranspose, TransposeFunc_07) {
  S21Matrix matrix{5, 10};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j / 10.0;
    }
  }

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 10);
  EXPECT_EQ(matrix_result.GetCols(), 5);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j), matrix(j, i));
    }
  }
}

TEST(S21MatrixTranspose, TransposeFunc_08) {
  S21Matrix matrix{10, 5};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j / 10.0;
    }
  }

  S21Matrix matrix_result{};
  ASSERT_NO_THROW(matrix_result = matrix.Transpose());

  EXPECT_EQ(matrix_result.GetRows(), 5);
  EXPECT_EQ(matrix_result.GetCols(), 10);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j), matrix(j, i));
    }
  }
}
