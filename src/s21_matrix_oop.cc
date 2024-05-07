#include "../includes/s21_matrix_oop.h"

//// Public

S21Matrix::S21Matrix() noexcept : rows_{0}, cols_{0}, matrix_{nullptr} {}

S21Matrix::S21Matrix(size_t rows, size_t cols)
    : rows_{rows}, cols_{cols}, matrix_{CreateMatrix(rows_, cols_)} {}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix{other.rows_, other.cols_} {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    free(matrix_);
    matrix_ = nullptr;
  }

  rows_ = 0;
  cols_ = 0;
}

//

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (!(other == *this)) {
    if (other.rows_ != rows_ || other.cols_ != cols_) {
      free(matrix_);
      matrix_ = nullptr;

      rows_ = 0;
      cols_ = 0;
    }

    {
      matrix_ = CreateMatrix(other.rows_, other.cols_);

      rows_ = other.rows_;
      cols_ = other.cols_;

      if (!std::memcpy(
              matrix_, other.matrix_,
              (rows_ * sizeof(double *)) + (cols_ * rows_ * sizeof(double)))) {
        throw std::logic_error("S21Matrix operator= - Memcpy error");
      }
    }
  }

  return *this;
}
S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (!(other == *this)) {
    free(matrix_);

    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;

    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }

  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);

  return *this;
}
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);

  return *this;
}
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);

  return *this;
}
S21Matrix &S21Matrix::operator*=(const double other) {
  MulNumber(other);

  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix temp_matrix{*this};

  temp_matrix.SumMatrix(other);

  return temp_matrix;
}
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix temp_matrix{*this};

  temp_matrix.SubMatrix(other);

  return temp_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix temp_matrix{*this};

  temp_matrix.MulMatrix(other);

  return temp_matrix;
}
S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix temp_matrix{*this};

  temp_matrix.MulNumber(num);

  return temp_matrix;
}
S21Matrix operator*(const double num, const S21Matrix &other) {
  S21Matrix temp_matrix{other};

  temp_matrix.MulNumber(num);

  return temp_matrix;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

double &S21Matrix::operator()(size_t row_index, size_t col_index) & {
  if (row_index >= rows_ || col_index >= cols_) {
    throw std::invalid_argument(
        "S21Matrix operator() & - incorrect rows\\cols");
  }

  return matrix_[row_index][col_index];
}
const double &S21Matrix::operator()(size_t row_index,
                                    size_t col_index) const & {
  if (row_index >= rows_ || col_index >= cols_) {
    throw std::invalid_argument(
        "S21Matrix operator() const & - incorrect rows\\cols");
  }

  return matrix_[row_index][col_index];
}

double S21Matrix::operator()(size_t row_index, size_t col_index) && {
  if (row_index >= rows_ || col_index >= cols_) {
    throw std::invalid_argument(
        "S21Matrix operator() && - incorrect rows\\cols");
  }

  return matrix_[row_index][col_index];
}
double S21Matrix::operator()(size_t row_index, size_t col_index) const && {
  if (row_index >= rows_ || col_index >= cols_) {
    throw std::invalid_argument(
        "S21Matrix operator() const && - incorrect rows\\cols");
  }

  return matrix_[row_index][col_index];
}

//

void S21Matrix::SetRows(size_t rows) {
  if (rows == rows_) {
    return;
  }

  S21Matrix result_matrix{rows, cols_};

  const size_t min = std::min(rows, rows_);
  for (size_t i = 0; i < min; ++i) {
    for (size_t j = 0; j < cols_; ++j) {
      result_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = std::move(result_matrix);
}
void S21Matrix::SetCols(size_t cols) {
  if (cols == cols_) {
    return;
  }

  S21Matrix result_matrix{rows_, cols};

  const size_t min = std::min(cols, cols_);
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < min; ++j) {
      result_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = std::move(result_matrix);
}

//

void S21Matrix::SumMatrix(const S21Matrix &other) {
  ArithmeticMatrix(other, '+');
}
void S21Matrix::SubMatrix(const S21Matrix &other) {
  ArithmeticMatrix(other, '-');
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > kEpsilon) {
        return false;
      }
    }
  }

  return true;
}

void S21Matrix::MulNumber(const double num) {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("MulMatrix error - rows != other.cols");
  }

  S21Matrix result_matrix{rows_, other.cols_};

  for (size_t i = 0; i < result_matrix.rows_; i++) {
    for (size_t j = 0; j < result_matrix.cols_; j++) {
      for (size_t o = 0; o < cols_; o++) {
        result_matrix.matrix_[i][j] += matrix_[i][o] * other.matrix_[o][j];
      }
    }
  }

  *this = std::move(result_matrix);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result_matrix{cols_, rows_};

  for (size_t i = 0; i < cols_; i++) {
    for (size_t j = 0; j < rows_; j++) {
      result_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }

  return result_matrix;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Determinant - rows != cols");
  }

  double determinant = 0;

  if (rows_ == 0) {
    return 0;
  } else if (rows_ == 1)
    determinant = matrix_[0][0];

  else if (rows_ == 2) {
    determinant = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix temp_matrix{*this};

    // (−1)^i+j = Чётное положительное / Нечётное = отрицательное
    int sign = 1;

    for (size_t i = 0; i < rows_; i++) {
      if (matrix_[0][i]) {
        determinant +=
            sign * matrix_[0][i] * temp_matrix.MinorMatrix(0, i).Determinant();

        sign = -sign;  // (i + j) % 2 ? -1 : 1;
      }
    }
  }

  return determinant;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2 || cols_ < 2) {
    throw std::invalid_argument("CalcComplements - incorrect matrix size");
  }

  S21Matrix result_matrix{rows_, cols_};

  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      result_matrix.matrix_[i][j] =
          this->MinorMatrix(i, j).Determinant() * pow(-1, i + j);
    }
  }

  return result_matrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_ || rows_ < 2 || cols_ < 2) {
    throw std::invalid_argument("InverseMatrix - incorrect matrix size");
  }

  const double determinant = Determinant();
  if (fabs(determinant) < kEpsilon) {
    throw std::invalid_argument("InverseMatrix - Determinant == 0");
  }

  return (CalcComplements().Transpose() * (1.0 / determinant));
}

//// Private

double **S21Matrix::CreateMatrix(size_t rows, size_t cols) {
  if (rows == 0 || cols == 0) {
    return nullptr;
  } else if (rows < 1 || cols < 1) {
    throw std::invalid_argument("CreateMatrix error - rows\\cols < 0");
  }

  double **matrix = (double **)calloc(
      1, (rows * sizeof(double *)) + (cols * rows * sizeof(double)));

  if (matrix) {
    matrix[0] = (double *)(matrix + rows);
    for (size_t i = 1; i < rows; i++) {
      matrix[i] = matrix[0] + i * cols;
    }

  } else {
    throw std::bad_alloc();  // ?
  }

  return matrix;
}

void S21Matrix::ArithmeticMatrix(const S21Matrix &other, char operation) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "ArithmeticMatrix error - rows\\cols not equal");
  }

  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      switch (operation) {
        case '+':
          matrix_[i][j] += other.matrix_[i][j];
          break;
        case '-':
          matrix_[i][j] -= other.matrix_[i][j];
          break;

        default:
          throw std::invalid_argument(
              "ArithmeticMatrix error - incorrect operation");
          break;
      }
    }
  }
}

S21Matrix S21Matrix::MinorMatrix(size_t excluded_row_index,
                                 size_t excluded_col_index) {
  if (excluded_row_index >= rows_ || excluded_col_index >= cols_) {
    throw std::invalid_argument("MinorMatrix - incorrect rows\\cols");
  }

  S21Matrix result_matrix{rows_ - 1, cols_ - 1};

  for (size_t i = 0, add_i = 0; i < rows_; i++) {
    if (i != excluded_row_index) {
      for (size_t j = 0, add_j = 0; j < cols_; j++) {
        if (j != excluded_col_index) {
          result_matrix.matrix_[i - add_i][j - add_j] = matrix_[i][j];
        } else {
          add_j = 1;
        }
      }

    } else {
      add_i = 1;
    }
  }

  return result_matrix;
}
