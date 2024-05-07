#include <gtest/gtest.h>

#include "../../includes/s21_matrix_oop.h"

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_00) {
  S21Matrix matrix{0, 0};

  matrix.MulMatrix(S21Matrix{0, 0});

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_01) {
  S21Matrix matrix{1, 1};

  matrix.MulMatrix(S21Matrix{1, 1});

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW(matrix.MulMatrix(S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW(matrix.MulMatrix(S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_04) {
  S21Matrix matrix{2, 3};

  ASSERT_ANY_THROW(matrix.MulMatrix(S21Matrix{2, 3}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_05) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_06) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), -15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_07) {
  S21Matrix matrix_1{3, 2};
  S21Matrix matrix_2{2, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 5;
  matrix_1(2, 0) = 3;
  matrix_1(2, 1) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = -1;
  matrix_2(0, 2) = 1;
  matrix_2(1, 0) = 2;
  matrix_2(1, 1) = 3;
  matrix_2(1, 2) = 4;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 9);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 11);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), 17);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 12);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 13);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 22);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), 15);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), 15);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 27);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_08) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  matrix_2(0, 0) = 9;
  matrix_2(0, 1) = 8;
  matrix_2(0, 2) = 7;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 5;
  matrix_2(1, 2) = 4;
  matrix_2(2, 0) = 3;
  matrix_2(2, 1) = 2;
  matrix_2(2, 2) = 1;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 30);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 24);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), 18);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 84);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 69);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 54);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), 138);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), 114);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 90);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulFunc_09) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 123.456;
  matrix_1(0, 1) = 0.287;
  matrix_1(0, 2) = -1298;
  matrix_1(1, 0) = 11;
  matrix_1(1, 1) = -9;
  matrix_1(1, 2) = 555;
  matrix_1(2, 0) = 0.192;
  matrix_1(2, 1) = -812;
  matrix_1(2, 2) = 0;

  matrix_2(0, 0) = 0;
  matrix_2(0, 1) = 878;
  matrix_2(0, 2) = 9.999;
  matrix_2(1, 0) = 321;
  matrix_2(1, 1) = 21;
  matrix_2(1, 2) = 12.1;
  matrix_2(2, 0) = 222;
  matrix_2(2, 1) = 0;
  matrix_2(2, 2) = 9;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), -288063.873);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 108400.395);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), -10444.090756);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 120321);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 9469);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 4996.089);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), -260652);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), -16883.424);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), -9823.280192);
}

///
////
///

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_00) {
  S21Matrix matrix{0, 0};

  matrix *= S21Matrix{0, 0};

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_01) {
  S21Matrix matrix{1, 1};

  matrix *= S21Matrix{1, 1};

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW((matrix *= S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW((matrix *= S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_04) {
  S21Matrix matrix{2, 3};

  ASSERT_ANY_THROW((matrix *= S21Matrix{2, 3}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_05) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1 *= matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_06) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -123.456;
  matrix_2(0, 0) = 123.456;

  matrix_1 *= matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), -15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_07) {
  S21Matrix matrix_1{3, 2};
  S21Matrix matrix_2{2, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 5;
  matrix_1(2, 0) = 3;
  matrix_1(2, 1) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = -1;
  matrix_2(0, 2) = 1;
  matrix_2(1, 0) = 2;
  matrix_2(1, 1) = 3;
  matrix_2(1, 2) = 4;

  matrix_1 *= matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 9);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 11);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), 17);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 12);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 13);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 22);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), 15);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), 15);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 27);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_08) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  matrix_2(0, 0) = 9;
  matrix_2(0, 1) = 8;
  matrix_2(0, 2) = 7;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 5;
  matrix_2(1, 2) = 4;
  matrix_2(2, 0) = 3;
  matrix_2(2, 1) = 2;
  matrix_2(2, 2) = 1;

  matrix_1 *= matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 30);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 24);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), 18);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 84);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 69);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 54);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), 138);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), 114);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 90);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulAssignmentOperator_09) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 123.456;
  matrix_1(0, 1) = 0.287;
  matrix_1(0, 2) = -1298;
  matrix_1(1, 0) = 11;
  matrix_1(1, 1) = -9;
  matrix_1(1, 2) = 555;
  matrix_1(2, 0) = 0.192;
  matrix_1(2, 1) = -812;
  matrix_1(2, 2) = 0;

  matrix_2(0, 0) = 0;
  matrix_2(0, 1) = 878;
  matrix_2(0, 2) = 9.999;
  matrix_2(1, 0) = 321;
  matrix_2(1, 1) = 21;
  matrix_2(1, 2) = 12.1;
  matrix_2(2, 0) = 222;
  matrix_2(2, 1) = 0;
  matrix_2(2, 2) = 9;

  matrix_1 *= matrix_2;

  EXPECT_EQ(matrix_1.GetRows(), 3);
  EXPECT_EQ(matrix_1.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), -288063.873);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 108400.395);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), -10444.090756);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 120321);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 9469);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 4996.089);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), -260652);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), -16883.424);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), -9823.280192);
}

///
////
///

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_00) {
  S21Matrix matrix{0, 0};

  const S21Matrix &&matrix_result = matrix * S21Matrix{0, 0};

  EXPECT_EQ(matrix_result.GetRows(), 0);
  EXPECT_EQ(matrix_result.GetCols(), 0);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_01) {
  S21Matrix matrix{1, 1};

  const S21Matrix &&matrix_result = matrix * S21Matrix{1, 1};

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_02) {
  S21Matrix matrix{0, 0};

  ASSERT_ANY_THROW((matrix * S21Matrix{1, 1}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_03) {
  S21Matrix matrix{1, 1};

  ASSERT_ANY_THROW((matrix * S21Matrix{0, 0}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_04) {
  S21Matrix matrix{2, 3};

  ASSERT_ANY_THROW((matrix * S21Matrix{2, 3}));
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_05) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = 123.456;
  matrix_2(0, 0) = 123.456;

  const S21Matrix &&matrix_result = matrix_1 * matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_06) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -123.456;
  matrix_2(0, 0) = 123.456;

  const S21Matrix &&matrix_result = matrix_1 * matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 1);
  EXPECT_EQ(matrix_result.GetCols(), 1);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), -15241.383936);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_07) {
  S21Matrix matrix_1{3, 2};
  S21Matrix matrix_2{2, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 5;
  matrix_1(2, 0) = 3;
  matrix_1(2, 1) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = -1;
  matrix_2(0, 2) = 1;
  matrix_2(1, 0) = 2;
  matrix_2(1, 1) = 3;
  matrix_2(1, 2) = 4;

  const S21Matrix &&matrix_result = matrix_1 * matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 3);
  EXPECT_EQ(matrix_result.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 9);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 11);
  EXPECT_DOUBLE_EQ(matrix_result(0, 2), 17);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 12);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 13);
  EXPECT_DOUBLE_EQ(matrix_result(1, 2), 22);
  EXPECT_DOUBLE_EQ(matrix_result(2, 0), 15);
  EXPECT_DOUBLE_EQ(matrix_result(2, 1), 15);
  EXPECT_DOUBLE_EQ(matrix_result(2, 2), 27);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_08) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  matrix_2(0, 0) = 9;
  matrix_2(0, 1) = 8;
  matrix_2(0, 2) = 7;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 5;
  matrix_2(1, 2) = 4;
  matrix_2(2, 0) = 3;
  matrix_2(2, 1) = 2;
  matrix_2(2, 2) = 1;

  const S21Matrix &&matrix_result = matrix_1 * matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 3);
  EXPECT_EQ(matrix_result.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 30);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 24);
  EXPECT_DOUBLE_EQ(matrix_result(0, 2), 18);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 84);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 69);
  EXPECT_DOUBLE_EQ(matrix_result(1, 2), 54);
  EXPECT_DOUBLE_EQ(matrix_result(2, 0), 138);
  EXPECT_DOUBLE_EQ(matrix_result(2, 1), 114);
  EXPECT_DOUBLE_EQ(matrix_result(2, 2), 90);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_09) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{3, 3};

  matrix_1(0, 0) = 123.456;
  matrix_1(0, 1) = 0.287;
  matrix_1(0, 2) = -1298;
  matrix_1(1, 0) = 11;
  matrix_1(1, 1) = -9;
  matrix_1(1, 2) = 555;
  matrix_1(2, 0) = 0.192;
  matrix_1(2, 1) = -812;
  matrix_1(2, 2) = 0;

  matrix_2(0, 0) = 0;
  matrix_2(0, 1) = 878;
  matrix_2(0, 2) = 9.999;
  matrix_2(1, 0) = 321;
  matrix_2(1, 1) = 21;
  matrix_2(1, 2) = 12.1;
  matrix_2(2, 0) = 222;
  matrix_2(2, 1) = 0;
  matrix_2(2, 2) = 9;

  const S21Matrix &&matrix_result = matrix_1 * matrix_2;

  EXPECT_EQ(matrix_result.GetRows(), 3);
  EXPECT_EQ(matrix_result.GetCols(), 3);

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), -288063.873);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 108400.395);
  EXPECT_DOUBLE_EQ(matrix_result(0, 2), -10444.090756);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 120321);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 9469);
  EXPECT_DOUBLE_EQ(matrix_result(1, 2), 4996.089);
  EXPECT_DOUBLE_EQ(matrix_result(2, 0), -260652);
  EXPECT_DOUBLE_EQ(matrix_result(2, 1), -16883.424);
  EXPECT_DOUBLE_EQ(matrix_result(2, 2), -9823.280192);
}

TEST(S21MatrixArithmeticMulMatrix, ArithmeticMulOperator_10) {
  S21Matrix matrix{0, 0};

  ASSERT_NO_THROW((S21Matrix{1, 1} * S21Matrix{1, 1}));
}