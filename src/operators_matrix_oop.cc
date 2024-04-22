#include "matrix_oop.h"

Matrix Matrix::operator+(const Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return Matrix();
  }

  Matrix result(*this);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] += other.matrix_[i][j];
    }
  }

  return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return Matrix();
  }

  Matrix result(*this);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] -= other.matrix_[i][j];
    }
  }

  return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
  if (cols_ != other.rows_) {
    return Matrix();
  }

  Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  return result;
}

Matrix Matrix::operator*(double num) const {
  Matrix result(*this);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] *= num;
    }
  }

  return result;
}

bool Matrix::operator==(const Matrix& other) const {
  return EqMatrix(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
  if (this == &other) {
    return *this;
  }

  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }

  rows_ = other.rows_;
  cols_ = other.cols_;

  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return *this;
  }

  for (int i = 0; i < GetRows(); ++i) {
    for (int j = 0; j < GetCols(); ++j) {
      GetMatrix()[i][j] += other.GetMatrix()[i][j];
    }
  }

  return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return *this;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }

  return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  if (cols_ != other.rows_) {
    return *this;
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

  return *this;
}

Matrix& Matrix::operator*=(double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }

  return *this;
}

double Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    return 0.0;
  }

  return matrix_[i][j];
}