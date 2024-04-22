#ifndef MATRIX_OOP_H
#define MATRIX_OOP_H

#include <cassert>
#include <iostream>

class Matrix {
 public:
  int GetRows() const;
  int GetCols() const;
  double** GetMatrix() const;
  void SetCols(int cols);
  void SetRows(int rows);

  // Constructors and destructors
  Matrix();                            // Basic constructor
  Matrix(int rows, int cols);          // Parametrized constructor
  Matrix(const Matrix& other);      // Copy constructor
  Matrix(Matrix&& other) noexcept;  // Move constructor
  ~Matrix();                           // Destructor

  // Operations
  bool EqMatrix(const Matrix& other) const;  // Checks for matrix equality
  void SumMatrix(const Matrix& other);       // Adds another matrix
  void SubMatrix(const Matrix& other);       // Subtracts a matrix
  void MulNumber(const double num);             // Multiplies matrix by a number
  void MulMatrix(const Matrix& other);  // Multiplies by the second matrix
  Matrix Transpose();                   // Transposed matrix
  Matrix CalcComplements();  // Calculates and returns the addition matrix
  double Determinant();         // Calculates and returns the determinant
  Matrix InverseMatrix();    // Calculates and returns the inverse matrix

  // Binary Operators
  Matrix operator+(const Matrix& other) const;  // Addition
  Matrix operator-(const Matrix& other) const;  // Subtraction
  Matrix operator*(const Matrix& other) const;  // Matrix Multiplication
  Matrix operator*(double num) const;              // Scalar Multiplication
  bool operator==(const Matrix& other) const;      // Equality

  // Assignment Operators
  Matrix& operator=(const Matrix& other);   // Assignment
  Matrix& operator+=(const Matrix& other);  // Addition Assignment
  Matrix& operator-=(const Matrix& other);  // Subtraction Assignment
  Matrix& operator*=(
      const Matrix& other);        // Matrix Multiplication Assignment
  Matrix& operator*=(double num);  // Scalar Multiplication Assignment

  // Function Operators
  double operator()(int i, int j) const;  // Matrix Element Access (Indexing)

 private:
  double** matrix_;
  int rows_;
  int cols_;
};

#endif  // MATRIX_OOP_H
