#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixAssignment, AssignmentRValueOperator_00) {
  S21Matrix matrix = S21Matrix{0, 0};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixAssignment, AssignmentRValueOperator_01) {
  S21Matrix matrix = S21Matrix{1, 1};

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix(0, 0), 0);
}

TEST(S21MatrixAssignment, AssignmentRValueOperator_02) {
  S21Matrix matrix{1, 1};
  matrix(0, 0) = 123.456;

  S21Matrix matrix_new;
  matrix_new = std::move(matrix);

  EXPECT_EQ(matrix_new.GetRows(), 1);
  EXPECT_EQ(matrix_new.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_new(0, 0), 123.456);
}

TEST(S21MatrixAssignment, AssignmentRValueOperator_03) {
  S21Matrix matrix{999, 999};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_new;
  matrix_new = std::move(matrix);

  EXPECT_EQ(matrix_new.GetRows(), 999);
  EXPECT_EQ(matrix_new.GetCols(), 999);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_new(i, j), i * matrix_new.GetCols() + j);
    }
  }
}

TEST(S21MatrixAssignment, AssignmentLValueOperator_00) {
  S21Matrix matrix{0, 0};

  S21Matrix matrix_new;
  matrix_new = matrix;

  EXPECT_EQ(matrix_new.GetRows(), 0);
  EXPECT_EQ(matrix_new.GetCols(), 0);
}

TEST(S21MatrixAssignment, AssignmentLValueOperator_01) {
  S21Matrix matrix{1, 1};

  S21Matrix matrix_new;
  matrix_new = matrix;

  EXPECT_EQ(matrix_new.GetRows(), 1);
  EXPECT_EQ(matrix_new.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_new(0, 0), 0);
}

TEST(S21MatrixAssignment, AssignmentLValueOperator_02) {
  S21Matrix matrix{1, 1};
  matrix(0, 0) = 123.456;

  S21Matrix matrix_new;
  matrix_new = matrix;

  EXPECT_EQ(matrix_new.GetRows(), 1);
  EXPECT_EQ(matrix_new.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_new(0, 0), 123.456);
}

TEST(S21MatrixAssignment, AssignmentLValueOperator_03) {
  S21Matrix matrix{999, 999};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_new;
  matrix_new = matrix;

  EXPECT_EQ(matrix_new.GetRows(), 999);
  EXPECT_EQ(matrix_new.GetCols(), 999);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), i * matrix.GetCols() + j);
      ASSERT_DOUBLE_EQ(matrix(i, j), matrix(i, j));
    }
  }
}
