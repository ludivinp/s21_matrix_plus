#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixSizeAccessors, ColsAccessor_00) {
  S21Matrix matrix{};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeAccessors, ColsAccessor_01) {
  S21Matrix matrix{0, 0};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeAccessors, ColsAccessor_02) {
  S21Matrix matrix{1, 0};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeAccessors, ColsAccessor_03) {
  S21Matrix matrix{1, 1};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixSizeAccessors, ColsAccessor_04) {
  S21Matrix matrix{999, 999};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 999);
}

TEST(S21MatrixSizeAccessors, ColsAccessor_05) {
  const S21Matrix matrix{999, 999};

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 999);
}

///
////
///

TEST(S21MatrixSizeAccessors, RowsAccessor_00) {
  S21Matrix matrix{};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeAccessors, RowsAccessor_01) {
  S21Matrix matrix{0, 0};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeAccessors, RowsAccessor_02) {
  S21Matrix matrix{0, 1};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeAccessors, RowsAccessor_03) {
  S21Matrix matrix{1, 1};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 1);
}

TEST(S21MatrixSizeAccessors, RowsAccessor_04) {
  S21Matrix matrix{999, 999};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 999);
}

TEST(S21MatrixSizeAccessors, RowsAccessor_05) {
  const S21Matrix matrix{999, 999};

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 999);
}