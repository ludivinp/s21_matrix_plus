#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixSizeMutators, ColsMutator_00) {
  S21Matrix matrix{};

  ASSERT_NO_THROW(matrix.SetCols(0));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeMutators, ColsMutator_01) {
  S21Matrix matrix{0, 0};

  ASSERT_NO_THROW(matrix.SetCols(0));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeMutators, ColsMutator_02) {
  S21Matrix matrix{1, 0};

  ASSERT_NO_THROW(matrix.SetCols(0));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixSizeMutators, ColsMutator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_NO_THROW(matrix.SetCols(1));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixSizeMutators, ColsMutator_04) {
  S21Matrix matrix{999, 999};

  ASSERT_NO_THROW(matrix.SetCols(999));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 999);
}

TEST(S21MatrixSizeMutators, ColsMutator_05) {
  S21Matrix matrix{0, 0};

  ASSERT_NO_THROW(matrix.SetCols(1));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixSizeMutators, ColsMutator_06) {
  S21Matrix matrix{1, 0};

  ASSERT_NO_THROW(matrix.SetCols(1));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 1);

  ASSERT_NO_THROW(matrix(0, 0) = 123.456);
  ASSERT_DOUBLE_EQ(matrix(0, 0), 123.456);
}

TEST(S21MatrixSizeMutators, ColsMutator_07) {
  S21Matrix matrix{5, 5};

  ASSERT_NO_THROW(matrix.SetCols(1));

  ASSERT_DOUBLE_EQ(matrix.GetCols(), 1);

  ASSERT_NO_THROW(matrix(0, 0) = 123.456);
  ASSERT_DOUBLE_EQ(matrix(0, 0), 123.456);
}

///
////
///

TEST(S21MatrixSizeMutators, RowsMutator_00) {
  S21Matrix matrix{};

  ASSERT_NO_THROW(matrix.SetRows(0));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeMutators, RowsMutator_01) {
  S21Matrix matrix{0, 0};

  ASSERT_NO_THROW(matrix.SetRows(0));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeMutators, RowsMutator_02) {
  S21Matrix matrix{0, 1};

  ASSERT_NO_THROW(matrix.SetRows(0));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 0);
}

TEST(S21MatrixSizeMutators, RowsMutator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_NO_THROW(matrix.SetRows(1));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 1);
}

TEST(S21MatrixSizeMutators, RowsMutator_04) {
  S21Matrix matrix{999, 999};

  ASSERT_NO_THROW(matrix.SetRows(999));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 999);
}

TEST(S21MatrixSizeMutators, RowsMutator_05) {
  S21Matrix matrix{0, 0};

  ASSERT_NO_THROW(matrix.SetRows(1));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 1);
}

TEST(S21MatrixSizeMutators, RowsMutator_06) {
  S21Matrix matrix{0, 1};

  ASSERT_NO_THROW(matrix.SetRows(1));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 1);

  ASSERT_NO_THROW(matrix(0, 0) = 123.456);
  ASSERT_DOUBLE_EQ(matrix(0, 0), 123.456);
}

TEST(S21MatrixSizeMutators, RowsMutator_07) {
  S21Matrix matrix{5, 5};

  ASSERT_NO_THROW(matrix.SetRows(1));

  ASSERT_DOUBLE_EQ(matrix.GetRows(), 1);

  ASSERT_NO_THROW(matrix(0, 0) = 123.456);
  ASSERT_DOUBLE_EQ(matrix(0, 0), 123.456);
}