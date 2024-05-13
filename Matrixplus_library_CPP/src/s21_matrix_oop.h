#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>

#include <cstring>
#include <iostream>

namespace S21 {
class S21Matrix {
 public:
  S21Matrix();
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  ~S21Matrix();

  int GetCols() const noexcept { return cols_; }
  int GetRows() const noexcept { return rows_; }
  void SetCols(const int cols);
  void SetRows(const int rows);

  bool EqMatrix(const S21Matrix& other) const;
  bool operator==(const S21Matrix& other) const;
  bool operator!=(const S21Matrix& other) const;

  void SumMatrix(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);

  void SubMatrix(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);

  void MulNumber(const double& num);
  S21Matrix operator*(const double& num) const;
  friend S21Matrix operator*(const double& num, const S21Matrix& other);
  S21Matrix& operator*=(const double& num);

  void MulMatrix(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);

  double& operator()(const int& i, const int& j);
  const double& operator()(const int& i, const int& j) const;

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  friend std::ostream& operator<<(std::ostream& out, const S21Matrix& other);
  friend std::istream& operator>>(std::istream& in, const S21Matrix& other);

 private:
  int rows_;
  int cols_;
  double** matrix_;
  bool IsEqualSize(const S21Matrix& other) const {
    return rows_ == other.rows_ && cols_ == other.cols_;
  }
  bool IsMatrixSquare() const { return rows_ == cols_; }
  double MulMainDiagonal() const;
  double MulSideDiagonal() const;
  void MoveLeft();
  S21Matrix CreateMinor(const int _i, const int _j) const;
};
}  // namespace S21

#endif  // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H