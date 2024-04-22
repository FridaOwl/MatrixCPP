#include "matrix_oop.h"

Matrix::Matrix() : matrix_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int rows, int cols)
    : matrix_(nullptr), rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  } else {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = 0.0;
      }
    }
  }
}

Matrix::Matrix(const Matrix& other)
    : matrix_(nullptr), rows_(other.rows_), cols_(other.cols_) {
  if (other.matrix_ != nullptr) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
    }

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

Matrix::Matrix(Matrix&& other) noexcept
    : matrix_(other.matrix_), rows_(other.rows_), cols_(other.cols_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

Matrix::~Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

int Matrix::GetRows() const { return rows_; }

int Matrix::GetCols() const { return cols_; }

double** Matrix::GetMatrix() const { return matrix_; }

void Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::out_of_range("Non-positive matrix size.");
  }

  double** new_matrix = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    new_matrix[i] = new double[cols];
  }

  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      new_matrix[row][col] = matrix_[row][col];
    }
  }

  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = new_matrix;
  cols_ = cols;
}

void Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::out_of_range("Non-positive matrix size.");
  }

  double** new_matrix = new double*[rows];
  for (int i = 0; i < rows; ++i) {
    new_matrix[i] = new double[cols_];
  }

  for (int row = 0; row < rows && row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      new_matrix[row][col] = matrix_[row][col];
    }
  }

  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = new_matrix;
  rows_ = rows;
}
