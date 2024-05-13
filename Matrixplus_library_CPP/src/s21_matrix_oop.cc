#include "s21_matrix_oop.h"

namespace S21 {
S21Matrix::S21Matrix() : rows_(5), cols_(5) {
  this->matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) throw std::length_error("Invalid matrix size");
  this->matrix_ = new double*[this->rows_]();
  for (int i = 0; i < rows_; i++) this->matrix_[i] = new double[this->cols_]();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix::S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < this->rows_; i++)
    std::memcpy(this->matrix_[i], other.matrix_[i],
                sizeof(double) * this->cols_);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) delete[] this->matrix_[i];
  delete[] this->matrix_;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;
  for (int i = 0; i < this->rows_; i++) delete[] matrix_[i];
  delete[] matrix_;
  this->cols_ = other.cols_;
  this->rows_ = other.rows_;

  matrix_ = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    matrix_[i] = new double[this->cols_];
    std::memcpy(this->matrix_[i], other.matrix_[i],
                sizeof(double) * this->cols_);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
  return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (!this->IsEqualSize(other)) return false;

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (this->matrix_[i][j] != other.matrix_[i][j]) return false;
    }
  }
  return true;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return this->EqMatrix(other);
}

bool S21Matrix::operator!=(const S21Matrix& other) const {
  return !(this->EqMatrix(other));
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!this->IsEqualSize(other))
    throw std::invalid_argument("both matrixes should be the same size");
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] += other.matrix_[i][j];
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!this->IsEqualSize(other))
    throw std::invalid_argument("both matrixes should be the same size");
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] -= other.matrix_[i][j];
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_)
    throw std::invalid_argument("these matrixes can't be multiplied");
  S21Matrix result(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      for (int k = 0; k < other.rows_; k++)
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

void S21Matrix::MulNumber(const double& num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) this->matrix_[i][j] *= num;
  }
}

S21Matrix S21Matrix::operator*(const double& num) const {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix operator*(const double& num, const S21Matrix& other) {
  return other * num;
}

double& S21Matrix::operator()(const int& i, const int& j) {
  if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0)
    throw std::invalid_argument("index out of range");
  return this->matrix_[i][j];
}

const double& S21Matrix::operator()(const int& i, const int& j) const {
  if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0)
    throw std::invalid_argument("index out of range");
  return this->matrix_[i][j];
}

void S21Matrix::SetCols(const int cols) {
  if (this->cols_ == cols) return;
  S21Matrix tmp(this->rows_, cols);
  for (int i = 0; i < this->rows_; i++)
    std::memcpy(
        tmp.matrix_[i], this->matrix_[i],
        this->cols_ < cols ? cols_ * sizeof(double*) : cols * sizeof(double*));
  *this = std::move(tmp);
}

void S21Matrix::SetRows(const int rows) {
  if (this->rows_ == rows) return;
  S21Matrix tmp(rows, this->cols_);
  for (int i = 0; i < rows; i++)
    std::memcpy(tmp.matrix_[i], matrix_[i], sizeof(double*) * this->cols_);
  *this = std::move(tmp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(this->cols_, this->rows_);
  for (int i = 0; i < this->cols_; i++) {
    for (int j = 0; j < this->rows_; j++)
      result.matrix_[i][j] = this->matrix_[j][i];
  }
  return result;
}

double S21Matrix::Determinant() {
  if (!this->IsMatrixSquare()) throw std::logic_error("Matrix is not square");
  if (rows_ == 1) return this->matrix_[0][0];
  if (rows_ == 2)
    return this->matrix_[0][0] * this->matrix_[1][1] -
           this->matrix_[0][1] * this->matrix_[1][0];
  S21Matrix tmp(*this);
  double sum_main_diagonal = 0.0;
  double sum_side_diagonal = 0.0;
  for (int i = 0; i < this->rows_; i++) {
    sum_main_diagonal += tmp.MulMainDiagonal();
    sum_side_diagonal += tmp.MulSideDiagonal();
    tmp.MoveLeft();
  }
  return sum_main_diagonal - sum_side_diagonal;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!this->IsMatrixSquare()) throw std::logic_error("Matrix is not square");
  S21Matrix result(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix minor = this->CreateMinor(i, j);
      result.matrix_[i][j] = minor.Determinant() * std::pow(-1, i + j + 2);
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (determinant == 0.0) throw std::logic_error("Determinant is 0");
  S21Matrix tmp = this->CalcComplements();
  S21Matrix res = tmp.Transpose();
  res *= 1.0 / determinant;
  return res;
}

S21Matrix S21Matrix::CreateMinor(const int _i, const int _j) const {
  int minor_i = 0;
  int minor_j = 0;
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (i != _i && j != _j) minor.matrix_[minor_i][minor_j++] = matrix_[i][j];
    }
    minor_j = 0;
    if (i != _i) ++minor_i;
  }
  return minor;
}

void S21Matrix::MoveLeft() {
  for (int i = 0; i < this->rows_; i++) {
    double tmp = this->matrix_[i][0];
    for (int j = 1; j < this->cols_; j++) {
      this->matrix_[i][j - 1] = this->matrix_[i][j];
    }
    this->matrix_[i][cols_ - 1] = tmp;
  }
}

double S21Matrix::MulMainDiagonal() const {
  double res = 1.0;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (i == j) res *= this->matrix_[i][j];
    }
  }
  return res;
}

double S21Matrix::MulSideDiagonal() const {
  double res = 1.0;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (j == this->rows_ - 1 - i) res *= this->matrix_[i][j];
    }
  }
  return res;
}

std::ostream& operator<<(std::ostream& out, const S21Matrix& other) {
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) out << other.matrix_[i][j] << ' ';
    out << '\n';
  }
  return out;
}

std::istream& operator>>(std::istream& in, const S21Matrix& other) {
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) in >> other.matrix_[i][j];
  }
  return in;
}

}  // namespace S21