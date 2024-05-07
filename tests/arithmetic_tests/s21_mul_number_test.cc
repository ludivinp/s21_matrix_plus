#include <gtest/gtest.h>

#include "../../includes/s21_matrix_oop.h"

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberFunc_00) {
  S21Matrix matrix{0, 0};

  matrix.MulNumber(123.456);

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberFunc_01) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  matrix.MulNumber(123.456);

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 123.456 * 123.456);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberFunc_02) {
  S21Matrix matrix{9, 9};
  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  matrix.MulNumber(123.456);

  EXPECT_EQ(matrix.GetRows(), 9);
  EXPECT_EQ(matrix.GetCols(), 9);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), (i * matrix.GetCols() + j) * 123.456);
    }
  }
}

///
////
///

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberAssignmentOperator_00) {
  S21Matrix matrix{0, 0};

  matrix *= 123.456;

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberAssignmentOperator_01) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  matrix *= 123.456;

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 123.456 * 123.456);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberAssignmentOperator_02) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  matrix *= 123.456;

  EXPECT_EQ(matrix.GetRows(), 9);
  EXPECT_EQ(matrix.GetCols(), 9);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), (i * matrix.GetCols() + j) * 123.456);
    }
  }
}

///
////
///

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorLeft_00) {
  S21Matrix matrix{0, 0};

  const S21Matrix &&matrix_result = matrix * 123.456;

  EXPECT_EQ(matrix_result.GetRows(), 0);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorLeft_01) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  const S21Matrix &&matrix_result = matrix * 123.456;

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 123.456 * 123.456);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorLeft_02) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  const S21Matrix &&matrix_result = matrix * 123.456;

  EXPECT_EQ(matrix_result.GetRows(), 9);
  EXPECT_EQ(matrix_result.GetCols(), 9);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j),
                       (i * matrix.GetCols() + j) * 123.456);
    }
  }
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorRight_00) {
  S21Matrix matrix{0, 0};

  const S21Matrix &&matrix_result = 123.456 * matrix;

  EXPECT_EQ(matrix_result.GetRows(), 0);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorRight_01) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  const S21Matrix &&matrix_result = 123.456 * matrix;

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 123.456 * 123.456);
}

TEST(S21MatrixArithmeticMulNumber, ArithmeticMulNumberOperatorRight_02) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  const S21Matrix &&matrix_result = 123.456 * matrix;

  EXPECT_EQ(matrix_result.GetRows(), 9);
  EXPECT_EQ(matrix_result.GetCols(), 9);

  for (size_t i = 0; i < matrix_result.GetRows(); i++) {
    for (size_t j = 0; j < matrix_result.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_result(i, j),
                       (i * matrix.GetCols() + j) * 123.456);
    }
  }
}
