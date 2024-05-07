#include <gtest/gtest.h>

#include "../includes/s21_matrix_oop.h"

TEST(S21MatrixConstructors, DefaultConstructor_00) {
  S21Matrix matrix{};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixConstructors, RowsColsConstructor_00) {
  S21Matrix matrix{0, 0};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixConstructors, RowsColsConstructor_01) {
  S21Matrix matrix{1, 1};

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix(0, 0), 0);
}

TEST(S21MatrixConstructors, RowsColsConstructor_02) {
  S21Matrix matrix{1, 9};

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 9);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), 0);
    }
  }
}

TEST(S21MatrixConstructors, RowsColsConstructor_03) {
  S21Matrix matrix{9, 1};

  EXPECT_EQ(matrix.GetRows(), 9);
  EXPECT_EQ(matrix.GetCols(), 1);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), 0);
    }
  }
}

TEST(S21MatrixConstructors, RowsColsConstructor_04) {
  S21Matrix matrix{999, 999};

  EXPECT_EQ(matrix.GetRows(), 999);
  EXPECT_EQ(matrix.GetCols(), 999);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), 0);
    }
  }
}

TEST(S21MatrixConstructors, CopyConstructor_00) {
  S21Matrix matrix{};
  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());
}

TEST(S21MatrixConstructors, CopyConstructor_01) {
  S21Matrix matrix{0, 0};

  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());
}

TEST(S21MatrixConstructors, CopyConstructor_02) {
  S21Matrix matrix{1, 1};

  matrix(0, 0) = 123.456;

  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), matrix_copy(i, j));
    }
  }
}

TEST(S21MatrixConstructors, CopyConstructor_03) {
  S21Matrix matrix{1, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());

  EXPECT_EQ(matrix_copy.GetRows(), 1);
  EXPECT_EQ(matrix_copy.GetCols(), 9);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), matrix_copy(i, j));
    }
  }
}

TEST(S21MatrixConstructors, CopyConstructor_04) {
  S21Matrix matrix{9, 1};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());

  EXPECT_EQ(matrix_copy.GetRows(), 9);
  EXPECT_EQ(matrix_copy.GetCols(), 1);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), matrix_copy(i, j));
    }
  }
}

TEST(S21MatrixConstructors, CopyConstructor_05) {
  S21Matrix matrix{999, 999};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_copy{matrix};

  EXPECT_EQ(matrix.GetRows(), matrix_copy.GetRows());
  EXPECT_EQ(matrix.GetCols(), matrix_copy.GetCols());

  EXPECT_EQ(matrix_copy.GetRows(), 999);
  EXPECT_EQ(matrix_copy.GetCols(), 999);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(matrix(i, j), matrix_copy(i, j));
    }
  }
}

TEST(S21MatrixConstructors, MoveConstructor_00) {
  S21Matrix matrix{S21Matrix{0, 0}};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixConstructors, MoveConstructor_01) {
  S21Matrix matrix{1, 1};
  matrix(0, 0) = 123.456;

  S21Matrix matrix_new{std::move(matrix)};

  EXPECT_EQ(matrix_new.GetRows(), 1);
  EXPECT_EQ(matrix_new.GetCols(), 1);

  ASSERT_DOUBLE_EQ(matrix_new(0, 0), 123.456);
}

TEST(S21MatrixConstructors, MoveConstructor_02) {
  S21Matrix matrix{1, 9};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_new{std::move(matrix)};

  EXPECT_EQ(matrix_new.GetRows(), 1);
  EXPECT_EQ(matrix_new.GetCols(), 9);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(i * matrix.GetCols() + j, matrix_new(i, j));
    }
  }
}

TEST(S21MatrixConstructors, MoveConstructor_03) {
  S21Matrix matrix{9, 1};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_new{std::move(matrix)};

  EXPECT_EQ(matrix_new.GetRows(), 9);
  EXPECT_EQ(matrix_new.GetCols(), 1);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(i * matrix.GetCols() + j, matrix_new(i, j));
    }
  }
}

TEST(S21MatrixConstructors, MoveConstructor_04) {
  S21Matrix matrix{999, 999};

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = i * matrix.GetCols() + j;
    }
  }

  S21Matrix matrix_new{std::move(matrix)};

  EXPECT_EQ(matrix_new.GetRows(), 999);
  EXPECT_EQ(matrix_new.GetCols(), 999);

  for (size_t i = 0; i < matrix.GetRows(); i++) {
    for (size_t j = 0; j < matrix.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(i * matrix.GetCols() + j, matrix_new(i, j));
    }
  }
}