#include <gtest/gtest.h>

#include "../../includes/s21_matrix_oop.h"

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_00) {
  S21Matrix matrix{0, 0};

  matrix.SumMatrix(S21Matrix{0, 0});

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_01) {
  S21Matrix matrix{1, 1};

  matrix.SumMatrix(S21Matrix{1, 1});

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW(matrix.SumMatrix(S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW(matrix.SumMatrix(S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_04) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1.SumMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 123.456 + 123.456);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumFunc_05) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j;
    }
  }

  matrix_1.SumMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 9);
  EXPECT_EQ(matrix_1.GetCols(), 9);

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), (i * matrix_1.GetCols() + j) +
                                           (i * matrix_1.GetCols() + j));
    }
  }
}

///
////
///

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_00) {
  S21Matrix matrix{0, 0};

  matrix += S21Matrix{0, 0};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_01) {
  S21Matrix matrix{1, 1};

  matrix += S21Matrix{1, 1};

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW((matrix += S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW((matrix += S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_04) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1 += matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 123.456 + 123.456);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumAssignmentOperator_05) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j;
    }
  }

  matrix_1 += matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 9);
  EXPECT_EQ(matrix_1.GetCols(), 9);

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), (i * matrix_1.GetCols() + j) +
                                           (i * matrix_1.GetCols() + j));
    }
  }
}

///
////
///

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_00) {
  S21Matrix matrix{0, 0};

  const S21Matrix &&matrix_result = matrix + S21Matrix{0, 0};

  EXPECT_EQ(matrix_result.GetRows(), 0);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_01) {
  S21Matrix matrix{1, 1};

  const S21Matrix &&matrix_result = matrix + S21Matrix{1, 1};

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW((matrix + S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW((matrix + S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_04) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  const S21Matrix &&matrix_result = matrix_1 + matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 123.456 + 123.456);
}

TEST(S21MatrixArithmeticSum, ArithmeticSumOperator_05) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j;
    }
  }

  const S21Matrix &&matrix_result = matrix_1 + matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 9);
  EXPECT_EQ(matrix_result.GetCols(), 9);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j), (i * matrix_1.GetCols() + j) +
                                                (i * matrix_1.GetCols() + j));
    }
  }
}
