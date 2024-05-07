#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixEqual, EqualFunc_00) {
  S21Matrix matrix{0, 0};

  ASSERT_TRUE(matrix.EqMatrix(S21Matrix{0, 0}));
}

TEST(S21MatrixEqual, EqualFunc_01) {
  S21Matrix matrix{1, 1};

  ASSERT_TRUE(matrix.EqMatrix(S21Matrix{1, 1}));
}

TEST(S21MatrixEqual, EqualFunc_02) {
  S21Matrix matrix{1, 1};

  ASSERT_FALSE(matrix.EqMatrix(S21Matrix{0, 0}));
}

TEST(S21MatrixEqual, EqualFunc_03) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  ASSERT_TRUE(matrix_1.EqMatrix(matrix_2));
}
TEST(S21MatrixEqual, EqualFunc_04) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -123.456;
  matrix_2(0, 0) = 123.456;

  ASSERT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixEqual, EqualFunc_05) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456789;
  matrix_2(0, 0) = 123.456780;

  ASSERT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixEqual, EqualFunc_06) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.4567899;
  matrix_2(0, 0) = 123.4567890;

  ASSERT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixEqual, EqualFunc_07) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j;
    }
  }

  ASSERT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixEqual, EqualFunc_08) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j + 1;
    }
  }

  ASSERT_FALSE(matrix_1.EqMatrix(matrix_2));
}

///
////
///

TEST(S21MatrixEqual, EqualOperator_00) {
  S21Matrix matrix{0, 0};

  ASSERT_TRUE((matrix == S21Matrix{0, 0}));
}

TEST(S21MatrixEqual, EqualOperator_01) {
  S21Matrix matrix{1, 1};

  ASSERT_TRUE((matrix == S21Matrix{1, 1}));
}

TEST(S21MatrixEqual, EqualOperator_02) {
  S21Matrix matrix{1, 1};

  ASSERT_FALSE((matrix == S21Matrix{0, 0}));
}

TEST(S21MatrixEqual, EqualOperator_03) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  ASSERT_TRUE((matrix_1 == matrix_2));
}
TEST(S21MatrixEqual, EqualOperator_04) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -123.456;
  matrix_2(0, 0) = 123.456;

  ASSERT_FALSE((matrix_1 == matrix_2));
}

TEST(S21MatrixEqual, EqualOperator_05) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456789;
  matrix_2(0, 0) = 123.456780;

  ASSERT_FALSE((matrix_1 == matrix_2));
}

TEST(S21MatrixEqual, EqualOperator_06) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.4567899;
  matrix_2(0, 0) = 123.4567890;

  ASSERT_TRUE((matrix_1 == matrix_2));
}

TEST(S21MatrixEqual, EqualOperator_07) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j;
    }
  }

  ASSERT_TRUE((matrix_1 == matrix_2));
}

TEST(S21MatrixEqual, EqualOperator_08) {
  S21Matrix matrix_1{9, 9};
  S21Matrix matrix_2{9, 9};

  for (size_t i = 0; i < matrix_1.GetRows(); i++) {
    for (size_t j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = i * matrix_1.GetCols() + j;
      matrix_2(i, j) = i * matrix_2.GetCols() + j + 1;
    }
  }

  ASSERT_FALSE((matrix_1 == matrix_2));
}