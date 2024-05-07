#pragma once

#include <cmath>
#include <cstring>
#include <exception>
#include <stdexcept>

class S21Matrix {
 public:
  static constexpr double kEpsilon{10e-7};

  //
  S21Matrix() noexcept;
  S21Matrix(size_t rows, size_t cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  ~S21Matrix();

  //
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);

  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double other);

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;

  S21Matrix operator*(const S21Matrix& other) const;

  S21Matrix operator*(const double num) const;
  friend S21Matrix operator*(const double num, const S21Matrix& other);

  bool operator==(const S21Matrix& other) const;

  double& operator()(size_t row_index, size_t col_index) &;
  const double& operator()(size_t row_index, size_t col_index) const&;

  double operator()(size_t row_index, size_t col_index) &&;
  double operator()(size_t row_index, size_t col_index) const&&;

  //

  inline size_t GetRows() const noexcept { return rows_; }
  inline size_t GetCols() const noexcept { return cols_; }

  void SetRows(size_t rows);
  void SetCols(size_t cols);

  //
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);

  bool EqMatrix(const S21Matrix& other) const;

  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();

  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

 private:
  double** CreateMatrix(size_t rows, size_t cols);

  void ArithmeticMatrix(const S21Matrix& other, char operation);

  S21Matrix MinorMatrix(size_t excluded_row_index, size_t excluded_col_index);

  size_t rows_, cols_;
  double** matrix_;
};