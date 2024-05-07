#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixParenthesis, ParenthesisLValueOperator_00) {
  S21Matrix matrix = S21Matrix{1, 1};

  ASSERT_DOUBLE_EQ(matrix(0, 0), 0);
}

TEST(S21MatrixParenthesis, ParenthesisLValueOperator_01) {
  S21Matrix matrix = S21Matrix{0, 0};

  ASSERT_ANY_THROW((matrix(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisLValueOperator_02) {
  S21Matrix matrix = S21Matrix{1, 0};

  ASSERT_ANY_THROW((matrix(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisLValueOperator_03) {
  S21Matrix matrix = S21Matrix{10, 10};

  ASSERT_ANY_THROW((matrix(100, 100)));
}

TEST(S21MatrixAssignment, ParenthesisLValueOperator_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  ASSERT_DOUBLE_EQ(matrix(0, 0), 123.456);
}

TEST(S21MatrixAssignment, ParenthesisLValueOperator_05) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), i * matrix.GetCols() + j);
    }
  }
}

///
////
///

TEST(S21MatrixParenthesis, ParenthesisLValueConstOperator_00) {
  const S21Matrix matrix = S21Matrix{1, 1};

  ASSERT_DOUBLE_EQ(matrix(0, 0), 0);
}

TEST(S21MatrixParenthesis, ParenthesisLValueConstOperator_01) {
  const S21Matrix matrix = S21Matrix{0, 0};

  ASSERT_ANY_THROW((matrix(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisLValueConstOperator_02) {
  const S21Matrix matrix = S21Matrix{1, 0};

  ASSERT_ANY_THROW((matrix(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisLValueConstOperator_03) {
  const S21Matrix matrix = S21Matrix{10, 10};

  ASSERT_ANY_THROW((matrix(100, 100)));
}

TEST(S21MatrixAssignment, ParenthesisLValueConstOperator_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  const S21Matrix matrix_const{matrix};

  ASSERT_DOUBLE_EQ(matrix_const(0, 0), 123.456);
}

TEST(S21MatrixAssignment, ParenthesisLValueConstOperator_05) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  const S21Matrix matrix_const{matrix};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix_const(i, j), i * matrix.GetCols() + j);
    }
  }
}

///
////
///

TEST(S21MatrixParenthesis, ParenthesisRValueOperator_00) {
  ASSERT_DOUBLE_EQ((S21Matrix{1, 1}(0, 0)), 0);
}

TEST(S21MatrixParenthesis, ParenthesisRValueOperator_01) {
  ASSERT_ANY_THROW((S21Matrix{0, 0}(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisRValueOperator_02) {
  S21Matrix matrix = S21Matrix{1, 0};

  ASSERT_ANY_THROW((S21Matrix{1, 0}(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisRValueOperator_03) {
  S21Matrix matrix = S21Matrix{10, 10};

  ASSERT_ANY_THROW((S21Matrix{10, 10}(100, 100)));
}

TEST(S21MatrixAssignment, ParenthesisRValueOperator_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  ASSERT_DOUBLE_EQ(std::move(matrix)(0, 0), 123.456);
}

TEST(S21MatrixAssignment, ParenthesisRValueOperator_05) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(std::move(matrix)(i, j), i * matrix.GetCols() + j);
    }
  }
}

///
////
///

TEST(S21MatrixParenthesis, ParenthesisRValueConstOperator_00) {
  const S21Matrix matrix = S21Matrix{1, 1};

  ASSERT_DOUBLE_EQ(std::move(matrix)(0, 0), 0);
}

TEST(S21MatrixParenthesis, ParenthesisRValueConstOperator_01) {
  const S21Matrix matrix = S21Matrix{0, 0};

  ASSERT_ANY_THROW((std::move(matrix)(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisRValueConstOperator_02) {
  const S21Matrix matrix = S21Matrix{1, 0};

  ASSERT_ANY_THROW((std::move(matrix)(0, 0)));
}

TEST(S21MatrixParenthesis, ParenthesisRValueConstOperator_03) {
  const S21Matrix matrix = S21Matrix{10, 10};

  ASSERT_ANY_THROW((std::move(matrix)(100, 100)));
}

TEST(S21MatrixAssignment, ParenthesisRValueConstOperator_04) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  const S21Matrix matrix_const{matrix};

  ASSERT_DOUBLE_EQ(std::move(matrix_const)(0, 0), 123.456);
}

TEST(S21MatrixAssignment, ParenthesisRValueConstOperator_05) {
  S21Matrix matrix{9, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  const S21Matrix matrix_const{matrix};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(std::move(matrix_const)(i, j), i * matrix.GetCols() + j);
    }
  }
}
