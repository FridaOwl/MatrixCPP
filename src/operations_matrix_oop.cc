#include "matrix_oop.h"

bool Matrix::EqMatrix(const Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols()) {
    std::cerr << "Incompatible matrix dimensions for addition." << std::endl;
  }

  for (int i = 0; i < GetRows(); ++i) {
    for (int j = 0; j < GetCols(); ++j) {
      GetMatrix()[i][j] += other.GetMatrix()[i][j];
    }
  }
}

void Matrix::SubMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    std::cerr << "Require matrices of equal size for subtraction." << std::endl;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void Matrix::MulMatrix(const Matrix& other) {
  if (cols_ != other.rows_) {
    std::cerr << "Unable to perform multiplication." << std::endl;
  }

  Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = result;
}

Matrix Matrix::Transpose() {
  Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

Matrix Matrix::CalcComplements() {
  if (rows_ != cols_) {
    std::cerr << "Is only defined for square matrices." << std::endl;
    return Matrix();
  }

  Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      Matrix minor(rows_ - 1, cols_ - 1);

      int minorRow = 0;
      int minorCol = 0;

      for (int row = 0; row < rows_; ++row) {
        if (row == i) {
          continue;
        }

        for (int col = 0; col < cols_; ++col) {
          if (col == j) {
            continue;
          }

          minor.matrix_[minorRow][minorCol] = matrix_[row][col];
          ++minorCol;
        }

        ++minorRow;
        minorCol = 0;
      }

      double minorDeterminant = minor.Determinant();

      double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;

      result.matrix_[i][j] = sign * minorDeterminant;
    }
  }

  return result;
}

double Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::runtime_error("Is only defined for square matrices.");
  }

  if (rows_ == 1) {
    return matrix_[0][0];
  }

  double det = 0.0;

  for (int j = 0; j < cols_; ++j) {
    Matrix minor(rows_ - 1, cols_ - 1);

    for (int row = 1; row < rows_; ++row) {
      int minorCol = 0;
      for (int col = 0; col < cols_; ++col) {
        if (col == j) {
          continue;
        }
        minor.matrix_[row - 1][minorCol] = matrix_[row][col];
        ++minorCol;
      }
    }

    double sign = (j % 2 == 0) ? 1.0 : -1.0;

    det += sign * matrix_[0][j] * minor.Determinant();
  }

  return det;
}

Matrix Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0.0) {
    std::cerr << "Matrix determinant is 0." << std::endl;
    return Matrix(rows_, cols_);
  }

  Matrix inverse(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      Matrix minor(rows_ - 1, cols_ - 1);
      int minorRow = 0;
      for (int row = 0; row < rows_; ++row) {
        if (row == i) {
          continue;
        }
        int minorCol = 0;
        for (int col = 0; col < cols_; ++col) {
          if (col == j) {
            continue;
          }
          minor.matrix_[minorRow][minorCol] = matrix_[row][col];
          ++minorCol;
        }
        ++minorRow;
      }

      double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;

      inverse.matrix_[j][i] = sign * minor.Determinant() / det;
    }
  }

  return inverse;
}