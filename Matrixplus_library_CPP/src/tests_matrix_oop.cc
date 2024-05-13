#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
using namespace S21;

TEST(EqMatrix, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);
  matrix_a(1, 1) = 0.6;
  matrix_b(1, 1) = 0.6;
  ASSERT_TRUE(matrix_a == matrix_b);
}
TEST(EqMatrix, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
  S21Matrix matrix_c(3, 3);
  matrix_c(1, 1) = 2;
  ASSERT_FALSE(matrix_a == matrix_c);
}

TEST(Determinant, true) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1;
  ASSERT_TRUE(matrix_a.Determinant() == 1);
  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 0;
  matrix_b(0, 1) = 5;
  matrix_b(1, 0) = 12;
  matrix_b(1, 1) = -55;
  ASSERT_TRUE(matrix_b.Determinant() == -60);
  S21Matrix matrix_c(3, 3);
  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 5;
  matrix_c(0, 2) = 7;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 3;
  matrix_c(1, 2) = 4;
  matrix_c(2, 0) = 5;
  matrix_c(2, 1) = -2;
  matrix_c(2, 2) = -3;
  ASSERT_TRUE(matrix_c.Determinant() == -1);
}

TEST(OperatorNotEqual, true) {
  S21Matrix matrix_a(1, 1);
  S21Matrix matrix_b(2, 2);
  ASSERT_TRUE(matrix_a != matrix_b);
}

TEST(CalcComplements, True) {
  S21Matrix matrix_a(2, 3);

  ASSERT_ANY_THROW(matrix_a.CalcComplements());
  S21Matrix matrix_c(3, 3);
  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 5;
  matrix_c(0, 2) = 7;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 3;
  matrix_c(1, 2) = 4;
  matrix_c(2, 0) = 5;
  matrix_c(2, 1) = -2;
  matrix_c(2, 2) = -3;

  S21Matrix res(3, 3);
  res(0, 0) = -1;
  res(0, 1) = 38;
  res(0, 2) = -27;
  res(1, 0) = 1;
  res(1, 1) = -41;
  res(1, 2) = 29;
  res(2, 0) = -1;
  res(2, 1) = 34;
  res(2, 2) = -24;

  ASSERT_TRUE(matrix_c.CalcComplements() == res);
}

TEST(SumMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a.SumMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(SumMatrix, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.SumMatrix(matrix_b));
}

TEST(SubMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  matrix_a.SubMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == result);
}
TEST(SubMatrix, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.SubMatrix(matrix_b));
}
TEST(MulNumber, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  matrix_a.MulNumber(10);

  ASSERT_TRUE(matrix_a == result);
}
TEST(MulMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = 3;
  matrix_a(1, 1) = 4;

  matrix_b(0, 0) = 5;
  matrix_b(0, 1) = 6;
  matrix_b(1, 0) = 7;
  matrix_b(1, 1) = 8;

  result(0, 0) = 19;
  result(0, 1) = 22;
  result(1, 0) = 43;
  result(1, 1) = 50;

  matrix_a.MulMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}
TEST(MulMatrix, False) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.MulMatrix(matrix_b));
}
TEST(OperatorParentheses, True) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_EQ(matrix_a(0, 1), 2);
  const S21Matrix matrix_b(2, 2);
  ASSERT_EQ(matrix_b(0, 0), 0);
  ASSERT_ANY_THROW(matrix_b(15, 15));
}

TEST(OperatorParentheses, False) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_NE(matrix_a(0, 1), 10);
}
TEST(OperatorShavronnes, True) {
  S21Matrix matrix_a(2, 2);
  std::stringstream input_date;
  input_date << "2 2 3 3";
  input_date >> matrix_a;
}
TEST(OperatorPlus, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((matrix_a + matrix_b) == result);
}
TEST(OperatorMinus, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((matrix_a - matrix_b) == result);
}
TEST(OperatorMultiplyMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = 3;
  matrix_a(1, 1) = 4;

  matrix_b(0, 0) = 5;
  matrix_b(0, 1) = 6;
  matrix_b(1, 0) = 7;
  matrix_b(1, 1) = 8;

  result(0, 0) = 19;
  result(0, 1) = 22;
  result(1, 0) = 43;
  result(1, 1) = 50;

  ASSERT_TRUE((matrix_a * matrix_b) == result);
}

TEST(OperatorBrac, True) {
  S21Matrix matrix_a(2, 2);
  ASSERT_ANY_THROW(matrix_a(-1, -1));
  ASSERT_ANY_THROW(matrix_a(10, 10));
}

TEST(OperatorMultiplyNumber, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
  ASSERT_TRUE((10 * matrix_a) == result);
}
TEST(OperatorMultiplyNum, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}
TEST(OperatorEqMatrix, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(1, 3);
  matrix_a = matrix_b;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(OperatorSumMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a += matrix_b;
  ASSERT_TRUE(matrix_a == result);
}
TEST(OperatorSumMatrix, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;
  ASSERT_ANY_THROW(matrix_a += matrix_b);
}

TEST(OperatorSubMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;
  matrix_a -= matrix_b;
  ASSERT_TRUE(matrix_a == result);
}
TEST(OperatorSubMatrix, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a -= matrix_b);
}
TEST(OperatorMulNumber, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a *= 10) == result);
}
TEST(OperatorMulMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = 3;
  matrix_a(1, 1) = 4;

  matrix_b(0, 0) = 5;
  matrix_b(0, 1) = 6;
  matrix_b(1, 0) = 7;
  matrix_b(1, 1) = 8;

  result(0, 0) = 19;
  result(0, 1) = 22;
  result(1, 0) = 43;
  result(1, 1) = 50;
  matrix_a *= matrix_b;
  ASSERT_TRUE(matrix_a == result);
}
TEST(OperatorMulMatrix, False) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a *= matrix_b);
}
TEST(Transpose, True) {
  S21Matrix matrix_a(2, 3);
  S21Matrix result(3, 2);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 4;
  matrix_a(1, 1) = 5;
  matrix_a(1, 2) = 6;

  result(0, 0) = 1;
  result(0, 1) = 4;
  result(1, 0) = 2;
  result(1, 1) = 5;
  result(2, 0) = 3;
  result(2, 1) = 6;

  S21Matrix res = matrix_a.Transpose();
  ASSERT_TRUE(res == result);
}
TEST(Constructorsrest, True) {
  ASSERT_ANY_THROW(S21Matrix matrix_a(0, 5));
  S21Matrix matrix_b;
  ASSERT_TRUE(matrix_b.GetRows() == 5 && matrix_b.GetCols() == 5);
}
TEST(Inverse, False) {
  S21Matrix matrix_a(4, 3);

  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;
  ASSERT_ANY_THROW(matrix_a.InverseMatrix());
}
TEST(Inverse, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix result(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  result(0, 0) = 1;
  result(0, 1) = -1;
  result(0, 2) = 1;
  result(1, 0) = -38;
  result(1, 1) = 41;
  result(1, 2) = -34;
  result(2, 0) = 27;
  result(2, 1) = -29;
  result(2, 2) = 24;

  ASSERT_TRUE(matrix_a.InverseMatrix().EqMatrix(result));
}

TEST(Get, True) {
  S21Matrix matrix_a(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  ASSERT_EQ(matrix_a.GetRows(), 3);
  ASSERT_EQ(matrix_a.GetCols(), 3);
}

TEST(Set, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix result(3, 2);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  result(0, 0) = 2;
  result(0, 1) = 5;

  result(1, 0) = 6;
  result(1, 1) = 3;

  result(2, 0) = 5;
  result(2, 1) = -2;
  matrix_a.SetCols(2);
  ASSERT_TRUE(matrix_a == result);
  S21Matrix matrix_b(3, 3);
  S21Matrix result_b(2, 3);

  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = -3;

  result_b(0, 0) = 2;
  result_b(0, 1) = 5;
  result_b(0, 2) = 7;
  result_b(1, 0) = 6;
  result_b(1, 1) = 3;
  result_b(1, 2) = 4;

  matrix_b.SetRows(2);
  ASSERT_TRUE(matrix_b == result_b);

  S21Matrix matrix_c(3, 3), result_c(3, 3);
  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 5;
  matrix_c(0, 2) = 7;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 3;
  matrix_c(1, 2) = 4;
  matrix_c(2, 0) = 5;
  matrix_c(2, 1) = -2;
  matrix_c(2, 2) = -3;

  result_c(0, 0) = 2;
  result_c(0, 1) = 5;
  result_c(0, 2) = 7;
  result_c(1, 0) = 6;
  result_c(1, 1) = 3;
  result_c(1, 2) = 4;
  result_c(2, 0) = 5;
  result_c(2, 1) = -2;
  result_c(2, 2) = -3;

  matrix_c.SetCols(3);
  matrix_c.SetRows(3);

  ASSERT_TRUE(matrix_c == result_c);

  ASSERT_ANY_THROW(matrix_c.SetRows(-5));

  ASSERT_ANY_THROW(matrix_c.SetCols(0));
}

TEST(MoveConstructor, True) {
  S21Matrix matrix_c(3, 3);
  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 5;
  matrix_c(0, 2) = 7;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 3;
  matrix_c(1, 2) = 4;
  matrix_c(2, 0) = 5;
  matrix_c(2, 1) = -2;
  matrix_c(2, 2) = -3;

  S21Matrix result = std::move(matrix_c);
  ASSERT_EQ(result(0, 0), 2);
  ASSERT_EQ(result(0, 1), 5);
  ASSERT_EQ(result(0, 2), 7);
  ASSERT_EQ(result(1, 0), 6);
  ASSERT_EQ(result(1, 1), 3);
  ASSERT_EQ(result(1, 2), 4);
  ASSERT_EQ(result(2, 0), 5);
  ASSERT_EQ(result(2, 1), -2);
  ASSERT_EQ(result(2, 2), -3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}