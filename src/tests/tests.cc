#include <gtest/gtest.h>

#include "../matrix_oop.h"

TEST(MatrixTest, SetCols) {
  Matrix matrix(2, 2);

  matrix.SetCols(3);

  EXPECT_EQ(matrix.GetCols(), 3);
}

TEST(MatrixTest, SetRows) {
  Matrix matrix(2, 2);

  matrix.SetRows(3);

  EXPECT_EQ(matrix.GetRows(), 3);
}

TEST(MatrixTest, GettersOneByOneMatrix) {
  Matrix matrix(1, 1);

  EXPECT_EQ(matrix.GetRows(), 1);

  EXPECT_EQ(matrix.GetCols(), 1);

  double** matrixData = matrix.GetMatrix();
  EXPECT_NE(matrixData, nullptr);

  EXPECT_DOUBLE_EQ(matrixData[0][0], 0.0);
}

TEST(MatrixTest, DefaultConstructor) {
  Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
  EXPECT_EQ(matrix.GetMatrix(), nullptr);
}

TEST(MatrixTest, ParameterizedConstructor) {
  Matrix matrix(3, 4);
  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 4);
  double** matrixData = matrix.GetMatrix();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      EXPECT_EQ(matrixData[i][j], 0.0);
    }
  }
}

TEST(MatrixTest, LargeParameterizedConstructor) {
  int rows = 1000;
  int cols = 1000;
  Matrix matrix(rows, cols);

  EXPECT_EQ(matrix.GetRows(), rows);
  EXPECT_EQ(matrix.GetCols(), cols);

  double** matrixData = matrix.GetMatrix();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(matrixData[i][j], 0.0);
    }
  }
}

TEST(MatrixTest, CopyConstructor) {
  Matrix original(2, 2);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[1][0] = 3.0;
  original.GetMatrix()[1][1] = 4.0;

  Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), 2);
  EXPECT_EQ(copy.GetCols(), 2);
  EXPECT_NE(copy.GetMatrix(), nullptr);

  double** copyData = copy.GetMatrix();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(copyData[i][j], original.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, CopyConstructorWith3x3Matrix) {
  Matrix original(3, 3);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[0][2] = 3.0;
  original.GetMatrix()[1][0] = 4.0;
  original.GetMatrix()[1][1] = 5.0;
  original.GetMatrix()[1][2] = 6.0;
  original.GetMatrix()[2][0] = 7.0;
  original.GetMatrix()[2][1] = 8.0;
  original.GetMatrix()[2][2] = 9.0;

  Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), 3);
  EXPECT_EQ(copy.GetCols(), 3);
  EXPECT_NE(copy.GetMatrix(), nullptr);

  double** copyData = copy.GetMatrix();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(copyData[i][j], original.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, EqMatrix) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[1][0] = 3.0;
  matrix1.GetMatrix()[1][1] = 4.0;

  Matrix matrix2(matrix1);

  Matrix matrix3(2, 2);
  matrix3.GetMatrix()[0][0] = 5.0;
  matrix3.GetMatrix()[0][1] = 6.0;
  matrix3.GetMatrix()[1][0] = 7.0;
  matrix3.GetMatrix()[1][1] = 8.0;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));

  EXPECT_FALSE(matrix1.EqMatrix(matrix3));
}

TEST(MatrixTest, EqMatrixWith3x3Matrix) {
  Matrix matrix1(3, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;
  matrix1.GetMatrix()[2][0] = 7.0;
  matrix1.GetMatrix()[2][1] = 8.0;
  matrix1.GetMatrix()[2][2] = 9.0;

  Matrix matrix2(matrix1);

  Matrix matrix3(3, 3);
  matrix3.GetMatrix()[0][0] = 1.0;
  matrix3.GetMatrix()[0][1] = 2.0;
  matrix3.GetMatrix()[0][2] = 3.0;
  matrix3.GetMatrix()[1][0] = 4.0;
  matrix3.GetMatrix()[1][1] = 5.0;
  matrix3.GetMatrix()[1][2] = 6.0;
  matrix3.GetMatrix()[2][0] = 7.0;
  matrix3.GetMatrix()[2][1] = 8.0;
  matrix3.GetMatrix()[2][2] = 10.0;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));

  EXPECT_FALSE(matrix1.EqMatrix(matrix3));
}

TEST(MatrixTest, SumMatrix) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[1][0] = 3.0;
  matrix1.GetMatrix()[1][1] = 4.0;

  Matrix matrix2(2, 2);
  matrix2.GetMatrix()[0][0] = 5.0;
  matrix2.GetMatrix()[0][1] = 6.0;
  matrix2.GetMatrix()[1][0] = 7.0;
  matrix2.GetMatrix()[1][1] = 8.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 6.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 8.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 10.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 12.0);
}

TEST(MatrixTest, SumMatrixWith3x3Matrix) {
  Matrix matrix1(3, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;
  matrix1.GetMatrix()[2][0] = 7.0;
  matrix1.GetMatrix()[2][1] = 8.0;
  matrix1.GetMatrix()[2][2] = 9.0;

  Matrix matrix2(3, 3);
  matrix2.GetMatrix()[0][0] = 10.0;
  matrix2.GetMatrix()[0][1] = 11.0;
  matrix2.GetMatrix()[0][2] = 12.0;
  matrix2.GetMatrix()[1][0] = 13.0;
  matrix2.GetMatrix()[1][1] = 14.0;
  matrix2.GetMatrix()[1][2] = 15.0;
  matrix2.GetMatrix()[2][0] = 16.0;
  matrix2.GetMatrix()[2][1] = 17.0;
  matrix2.GetMatrix()[2][2] = 18.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 11.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 13.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][2], 15.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 17.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 19.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][2], 21.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][0], 23.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][1], 25.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][2], 27.0);
}

TEST(MatrixTest, SubMatrix) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 5.0;
  matrix1.GetMatrix()[0][1] = 6.0;
  matrix1.GetMatrix()[1][0] = 7.0;
  matrix1.GetMatrix()[1][1] = 8.0;

  Matrix matrix2(2, 2);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[1][0] = 3.0;
  matrix2.GetMatrix()[1][1] = 4.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 4.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 4.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 4.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 4.0);
}

TEST(MatrixTest, SubMatrixWith3x3Matrix) {
  Matrix matrix1(3, 3);
  matrix1.GetMatrix()[0][0] = 10.0;
  matrix1.GetMatrix()[0][1] = 11.0;
  matrix1.GetMatrix()[0][2] = 12.0;
  matrix1.GetMatrix()[1][0] = 13.0;
  matrix1.GetMatrix()[1][1] = 14.0;
  matrix1.GetMatrix()[1][2] = 15.0;
  matrix1.GetMatrix()[2][0] = 16.0;
  matrix1.GetMatrix()[2][1] = 17.0;
  matrix1.GetMatrix()[2][2] = 18.0;

  Matrix matrix2(3, 3);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[0][2] = 3.0;
  matrix2.GetMatrix()[1][0] = 4.0;
  matrix2.GetMatrix()[1][1] = 5.0;
  matrix2.GetMatrix()[1][2] = 6.0;
  matrix2.GetMatrix()[2][0] = 7.0;
  matrix2.GetMatrix()[2][1] = 8.0;
  matrix2.GetMatrix()[2][2] = 9.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][2], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][2], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][0], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][1], 9.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][2], 9.0);
}

TEST(MatrixTest, MulNumber) {
  Matrix matrix(2, 2);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[1][0] = 3.0;
  matrix.GetMatrix()[1][1] = 4.0;

  matrix.MulNumber(2.0);

  EXPECT_EQ(matrix.GetMatrix()[0][0], 2.0);
  EXPECT_EQ(matrix.GetMatrix()[0][1], 4.0);
  EXPECT_EQ(matrix.GetMatrix()[1][0], 6.0);
  EXPECT_EQ(matrix.GetMatrix()[1][1], 8.0);
}

TEST(MatrixTest, MulNumber3x3) {
  Matrix matrix(3, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;
  matrix.GetMatrix()[2][0] = 7.0;
  matrix.GetMatrix()[2][1] = 8.0;
  matrix.GetMatrix()[2][2] = 9.0;

  matrix.MulNumber(2.0);

  EXPECT_EQ(matrix.GetMatrix()[0][0], 2.0);
  EXPECT_EQ(matrix.GetMatrix()[0][1], 4.0);
  EXPECT_EQ(matrix.GetMatrix()[0][2], 6.0);
  EXPECT_EQ(matrix.GetMatrix()[1][0], 8.0);
  EXPECT_EQ(matrix.GetMatrix()[1][1], 10.0);
  EXPECT_EQ(matrix.GetMatrix()[1][2], 12.0);
  EXPECT_EQ(matrix.GetMatrix()[2][0], 14.0);
  EXPECT_EQ(matrix.GetMatrix()[2][1], 16.0);
  EXPECT_EQ(matrix.GetMatrix()[2][2], 18.0);
}

TEST(MatrixTest, MulMatrix) {
  Matrix matrix1(2, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;

  Matrix matrix2(3, 2);
  matrix2.GetMatrix()[0][0] = 7.0;
  matrix2.GetMatrix()[0][1] = 8.0;
  matrix2.GetMatrix()[1][0] = 9.0;
  matrix2.GetMatrix()[1][1] = 10.0;
  matrix2.GetMatrix()[2][0] = 11.0;
  matrix2.GetMatrix()[2][1] = 12.0;

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 58.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 64.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 139.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 154.0);
}

TEST(MatrixTest, MulMatrix3x3) {
  Matrix matrix1(3, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;
  matrix1.GetMatrix()[2][0] = 7.0;
  matrix1.GetMatrix()[2][1] = 8.0;
  matrix1.GetMatrix()[2][2] = 9.0;

  Matrix matrix2(3, 3);
  matrix2.GetMatrix()[0][0] = 10.0;
  matrix2.GetMatrix()[0][1] = 11.0;
  matrix2.GetMatrix()[0][2] = 12.0;
  matrix2.GetMatrix()[1][0] = 13.0;
  matrix2.GetMatrix()[1][1] = 14.0;
  matrix2.GetMatrix()[1][2] = 15.0;
  matrix2.GetMatrix()[2][0] = 16.0;
  matrix2.GetMatrix()[2][1] = 17.0;
  matrix2.GetMatrix()[2][2] = 18.0;

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetCols(), 3);

  EXPECT_EQ(matrix1.GetMatrix()[0][0], 84.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][1], 90.0);
  EXPECT_EQ(matrix1.GetMatrix()[0][2], 96.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][0], 201.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][1], 216.0);
  EXPECT_EQ(matrix1.GetMatrix()[1][2], 231.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][0], 318.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][1], 342.0);
  EXPECT_EQ(matrix1.GetMatrix()[2][2], 366.0);
}

TEST(MatrixTest, Transpose) {
  Matrix original(2, 3);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[0][2] = 3.0;
  original.GetMatrix()[1][0] = 4.0;
  original.GetMatrix()[1][1] = 5.0;
  original.GetMatrix()[1][2] = 6.0;

  Matrix transposed = original.Transpose();

  EXPECT_EQ(transposed.GetRows(), original.GetCols());
  EXPECT_EQ(transposed.GetCols(), original.GetRows());

  EXPECT_EQ(transposed.GetMatrix()[0][0], 1.0);
  EXPECT_EQ(transposed.GetMatrix()[1][0], 2.0);
  EXPECT_EQ(transposed.GetMatrix()[2][0], 3.0);
  EXPECT_EQ(transposed.GetMatrix()[0][1], 4.0);
  EXPECT_EQ(transposed.GetMatrix()[1][1], 5.0);
  EXPECT_EQ(transposed.GetMatrix()[2][1], 6.0);
}

TEST(MatrixTest, Transpose5x3) {
  Matrix original(5, 3);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[0][2] = 3.0;
  original.GetMatrix()[1][0] = 4.0;
  original.GetMatrix()[1][1] = 5.0;
  original.GetMatrix()[1][2] = 6.0;
  original.GetMatrix()[2][0] = 7.0;
  original.GetMatrix()[2][1] = 8.0;
  original.GetMatrix()[2][2] = 9.0;
  original.GetMatrix()[3][0] = 10.0;
  original.GetMatrix()[3][1] = 11.0;
  original.GetMatrix()[3][2] = 12.0;
  original.GetMatrix()[4][0] = 13.0;
  original.GetMatrix()[4][1] = 14.0;
  original.GetMatrix()[4][2] = 15.0;

  Matrix transposed = original.Transpose();

  EXPECT_EQ(transposed.GetRows(), original.GetCols());
  EXPECT_EQ(transposed.GetCols(), original.GetRows());

  EXPECT_EQ(transposed.GetMatrix()[0][0], 1.0);
  EXPECT_EQ(transposed.GetMatrix()[0][1], 4.0);
  EXPECT_EQ(transposed.GetMatrix()[0][2], 7.0);
  EXPECT_EQ(transposed.GetMatrix()[0][3], 10.0);
  EXPECT_EQ(transposed.GetMatrix()[0][4], 13.0);

  EXPECT_EQ(transposed.GetMatrix()[1][0], 2.0);
  EXPECT_EQ(transposed.GetMatrix()[1][1], 5.0);
  EXPECT_EQ(transposed.GetMatrix()[1][2], 8.0);
  EXPECT_EQ(transposed.GetMatrix()[1][3], 11.0);
  EXPECT_EQ(transposed.GetMatrix()[1][4], 14.0);

  EXPECT_EQ(transposed.GetMatrix()[2][0], 3.0);
  EXPECT_EQ(transposed.GetMatrix()[2][1], 6.0);
  EXPECT_EQ(transposed.GetMatrix()[2][2], 9.0);
  EXPECT_EQ(transposed.GetMatrix()[2][3], 12.0);
  EXPECT_EQ(transposed.GetMatrix()[2][4], 15.0);
}

TEST(MatrixTest, Determinant) {
  Matrix matrix(3, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;
  matrix.GetMatrix()[2][0] = 7.0;
  matrix.GetMatrix()[2][1] = 8.0;
  matrix.GetMatrix()[2][2] = 9.0;

  double determinant = matrix.Determinant();

  EXPECT_EQ(determinant, 0.0);
}

TEST(MatrixTest, CalcComplements) {
  Matrix matrix(2, 2);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[1][0] = 3.0;
  matrix.GetMatrix()[1][1] = 4.0;

  Matrix complements = matrix.CalcComplements();

  EXPECT_EQ(complements.GetRows(), 2);
  EXPECT_EQ(complements.GetCols(), 2);

  EXPECT_EQ(complements.GetMatrix()[0][0], 4.0);
  EXPECT_EQ(complements.GetMatrix()[0][1], -3.0);
  EXPECT_EQ(complements.GetMatrix()[1][0], -2.0);
  EXPECT_EQ(complements.GetMatrix()[1][1], 1.0);
}

TEST(MatrixTest, InverseMatrix) {
  Matrix matrix(2, 2);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[1][0] = 3.0;
  matrix.GetMatrix()[1][1] = 4.0;

  Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.GetRows(), 2);
  EXPECT_EQ(inverse.GetCols(), 2);

  double epsilon = 1e-6;

  EXPECT_NEAR(inverse.GetMatrix()[0][0], -2.0, epsilon);
  EXPECT_NEAR(inverse.GetMatrix()[0][1], 1.0, epsilon);
  EXPECT_NEAR(inverse.GetMatrix()[1][0], 1.5, epsilon);
  EXPECT_NEAR(inverse.GetMatrix()[1][1], -0.5, epsilon);

  Matrix identity = matrix * inverse;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (i == j) {
        EXPECT_NEAR(identity.GetMatrix()[i][j], 1.0, epsilon);
      } else {
        EXPECT_NEAR(identity.GetMatrix()[i][j], 0.0, epsilon);
      }
    }
  }
}

TEST(MatrixTest, MatrixAddition) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[1][0] = 3.0;
  matrix1.GetMatrix()[1][1] = 4.0;

  Matrix matrix2(2, 2);
  matrix2.GetMatrix()[0][0] = 5.0;
  matrix2.GetMatrix()[0][1] = 6.0;
  matrix2.GetMatrix()[1][0] = 7.0;
  matrix2.GetMatrix()[1][1] = 8.0;

  Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][0], 6.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][1], 8.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][0], 10.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][1], 12.0);
}

TEST(MatrixTest, MatrixSubtraction) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 5.0;
  matrix1.GetMatrix()[0][1] = 6.0;
  matrix1.GetMatrix()[1][0] = 7.0;
  matrix1.GetMatrix()[1][1] = 8.0;

  Matrix matrix2(2, 2);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[1][0] = 3.0;
  matrix2.GetMatrix()[1][1] = 4.0;

  Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][0], 4.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][1], 4.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][0], 4.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][1], 4.0);
}

TEST(MatrixTest, MatrixMultiplication) {
  Matrix matrix1(2, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;

  Matrix matrix2(3, 2);
  matrix2.GetMatrix()[0][0] = 7.0;
  matrix2.GetMatrix()[0][1] = 8.0;
  matrix2.GetMatrix()[1][0] = 9.0;
  matrix2.GetMatrix()[1][1] = 10.0;
  matrix2.GetMatrix()[2][0] = 11.0;
  matrix2.GetMatrix()[2][1] = 12.0;

  Matrix result = matrix1 * matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][0], 58.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][1], 64.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][0], 139.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][1], 154.0);
}

TEST(MatrixTest, MatrixScalarMultiplication) {
  Matrix matrix(2, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;

  double scalar = 2.5;
  Matrix result = matrix * scalar;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][0], 2.5);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][1], 5.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][2], 7.5);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][0], 10.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][1], 12.5);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][2], 15.0);
}

TEST(MatrixTest, MatrixScalarMultiplication3x3) {
  Matrix matrix(3, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;
  matrix.GetMatrix()[2][0] = 7.0;
  matrix.GetMatrix()[2][1] = 8.0;
  matrix.GetMatrix()[2][2] = 9.0;

  double scalar = 2.0;
  Matrix result = matrix * scalar;

  EXPECT_EQ(result.GetRows(), 3);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][0], 2.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][1], 4.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[0][2], 6.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][0], 8.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][1], 10.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[1][2], 12.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[2][0], 14.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[2][1], 16.0);
  EXPECT_DOUBLE_EQ(result.GetMatrix()[2][2], 18.0);
}

bool AreMatricesEqual(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.GetRows() != matrix2.GetRows() ||
      matrix1.GetCols() != matrix2.GetCols()) {
    return false;
  }

  for (int i = 0; i < matrix1.GetRows(); ++i) {
    for (int j = 0; j < matrix1.GetCols(); ++j) {
      if (matrix1.GetMatrix()[i][j] != matrix2.GetMatrix()[i][j]) {
        return false;
      }
    }
  }

  return true;
}

TEST(MatrixTest, MatrixInequalityOperator) {
  Matrix matrix1(2, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;

  Matrix matrix2(2, 3);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[0][2] = 3.0;
  matrix2.GetMatrix()[1][0] = 4.0;
  matrix2.GetMatrix()[1][1] = 5.0;
  matrix2.GetMatrix()[1][2] = 6.0;

  Matrix matrix3(2, 3);
  matrix3.GetMatrix()[0][0] = 1.0;
  matrix3.GetMatrix()[0][1] = 2.0;
  matrix3.GetMatrix()[0][2] = 3.0;
  matrix3.GetMatrix()[1][0] = 4.0;
  matrix3.GetMatrix()[1][1] = 5.0;
  matrix3.GetMatrix()[1][2] = 7.0;

  EXPECT_FALSE(AreMatricesEqual(matrix1, matrix3));
  EXPECT_FALSE(AreMatricesEqual(matrix2, matrix3));
}

TEST(MatrixTest, MatrixInequalityOperator3x3) {
  Matrix matrix1(3, 3);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[0][2] = 3.0;
  matrix1.GetMatrix()[1][0] = 4.0;
  matrix1.GetMatrix()[1][1] = 5.0;
  matrix1.GetMatrix()[1][2] = 6.0;
  matrix1.GetMatrix()[2][0] = 7.0;
  matrix1.GetMatrix()[2][1] = 8.0;
  matrix1.GetMatrix()[2][2] = 9.0;

  Matrix matrix2(3, 3);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[0][2] = 3.0;
  matrix2.GetMatrix()[1][0] = 4.0;
  matrix2.GetMatrix()[1][1] = 5.0;
  matrix2.GetMatrix()[1][2] = 6.0;
  matrix2.GetMatrix()[2][0] = 7.0;
  matrix2.GetMatrix()[2][1] = 8.0;
  matrix2.GetMatrix()[2][2] = 9.0;

  Matrix matrix3(3, 3);
  matrix3.GetMatrix()[0][0] = 1.0;
  matrix3.GetMatrix()[0][1] = 2.0;
  matrix3.GetMatrix()[0][2] = 3.0;
  matrix3.GetMatrix()[1][0] = 4.0;
  matrix3.GetMatrix()[1][1] = 5.0;
  matrix3.GetMatrix()[1][2] = 7.0;
  matrix3.GetMatrix()[2][0] = 7.0;
  matrix3.GetMatrix()[2][1] = 8.0;
  matrix3.GetMatrix()[2][2] = 9.0;

  EXPECT_FALSE(AreMatricesEqual(matrix1, matrix3));
  EXPECT_FALSE(AreMatricesEqual(matrix2, matrix3));
}

TEST(MatrixTest, AssignmentOperator) {
  Matrix original(2, 3);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[0][2] = 3.0;
  original.GetMatrix()[1][0] = 4.0;
  original.GetMatrix()[1][1] = 5.0;
  original.GetMatrix()[1][2] = 6.0;

  Matrix assigned;
  assigned = original;

  EXPECT_EQ(assigned.GetRows(), original.GetRows());
  EXPECT_EQ(assigned.GetCols(), original.GetCols());

  double** assignedData = assigned.GetMatrix();
  double** originalData = original.GetMatrix();

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_EQ(assignedData[i][j], originalData[i][j]);
    }
  }

  original = original;
  EXPECT_EQ(original.GetRows(), 2);
  EXPECT_EQ(original.GetCols(), 3);
}

TEST(MatrixTest, AssignmentOperator3x3) {
  Matrix original(3, 3);
  original.GetMatrix()[0][0] = 1.0;
  original.GetMatrix()[0][1] = 2.0;
  original.GetMatrix()[0][2] = 3.0;
  original.GetMatrix()[1][0] = 4.0;
  original.GetMatrix()[1][1] = 5.0;
  original.GetMatrix()[1][2] = 6.0;
  original.GetMatrix()[2][0] = 7.0;
  original.GetMatrix()[2][1] = 8.0;
  original.GetMatrix()[2][2] = 9.0;

  original = original;

  EXPECT_EQ(original.GetRows(), 3);
  EXPECT_EQ(original.GetCols(), 3);

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(original(i, j), i * original.GetCols() + j + 1.0);
    }
  }
}

TEST(MatrixTest, MatrixAdditionOperator) {
  Matrix matrix(2, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;

  Matrix otherMatrix(2, 3);
  otherMatrix.GetMatrix()[0][0] = 2.0;
  otherMatrix.GetMatrix()[0][1] = 3.0;
  otherMatrix.GetMatrix()[0][2] = 4.0;
  otherMatrix.GetMatrix()[1][0] = 5.0;
  otherMatrix.GetMatrix()[1][1] = 6.0;
  otherMatrix.GetMatrix()[1][2] = 7.0;

  Matrix originalMatrix = matrix;

  matrix += otherMatrix;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix.GetMatrix()[i][j], originalMatrix.GetMatrix()[i][j] +
                                              otherMatrix.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, MatrixAdditionOperator3x4) {
  Matrix matrix(3, 4);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[0][3] = 4.0;
  matrix.GetMatrix()[1][0] = 5.0;
  matrix.GetMatrix()[1][1] = 6.0;
  matrix.GetMatrix()[1][2] = 7.0;
  matrix.GetMatrix()[1][3] = 8.0;
  matrix.GetMatrix()[2][0] = 9.0;
  matrix.GetMatrix()[2][1] = 10.0;
  matrix.GetMatrix()[2][2] = 11.0;
  matrix.GetMatrix()[2][3] = 12.0;

  Matrix otherMatrix(3, 4);
  otherMatrix.GetMatrix()[0][0] = 2.0;
  otherMatrix.GetMatrix()[0][1] = 3.0;
  otherMatrix.GetMatrix()[0][2] = 4.0;
  otherMatrix.GetMatrix()[0][3] = 5.0;
  otherMatrix.GetMatrix()[1][0] = 6.0;
  otherMatrix.GetMatrix()[1][1] = 7.0;
  otherMatrix.GetMatrix()[1][2] = 8.0;
  otherMatrix.GetMatrix()[1][3] = 9.0;
  otherMatrix.GetMatrix()[2][0] = 10.0;
  otherMatrix.GetMatrix()[2][1] = 11.0;
  otherMatrix.GetMatrix()[2][2] = 12.0;
  otherMatrix.GetMatrix()[2][3] = 13.0;

  Matrix originalMatrix = matrix;

  matrix += otherMatrix;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix.GetMatrix()[i][j], originalMatrix.GetMatrix()[i][j] +
                                              otherMatrix.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, MatrixSubtractionOperator) {
  Matrix matrix(2, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;

  Matrix otherMatrix(2, 3);
  otherMatrix.GetMatrix()[0][0] = 2.0;
  otherMatrix.GetMatrix()[0][1] = 3.0;
  otherMatrix.GetMatrix()[0][2] = 4.0;
  otherMatrix.GetMatrix()[1][0] = 5.0;
  otherMatrix.GetMatrix()[1][1] = 6.0;
  otherMatrix.GetMatrix()[1][2] = 7.0;

  Matrix originalMatrix = matrix;

  matrix -= otherMatrix;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix.GetMatrix()[i][j], originalMatrix.GetMatrix()[i][j] -
                                              otherMatrix.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, MatrixMultiplicationOperator) {
  Matrix matrix(2, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;

  Matrix otherMatrix(3, 2);
  otherMatrix.GetMatrix()[0][0] = 2.0;
  otherMatrix.GetMatrix()[0][1] = 3.0;
  otherMatrix.GetMatrix()[1][0] = 4.0;
  otherMatrix.GetMatrix()[1][1] = 5.0;
  otherMatrix.GetMatrix()[2][0] = 6.0;
  otherMatrix.GetMatrix()[2][1] = 7.0;

  Matrix originalMatrix = matrix;

  matrix *= otherMatrix;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      double expectedValue = 0.0;
      for (int k = 0; k < originalMatrix.GetCols(); ++k) {
        expectedValue +=
            originalMatrix.GetMatrix()[i][k] * otherMatrix.GetMatrix()[k][j];
      }
      EXPECT_EQ(matrix.GetMatrix()[i][j], expectedValue);
    }
  }
}

TEST(MatrixTest, MatrixSubtractionOperator3x3) {
  Matrix matrix(3, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;
  matrix.GetMatrix()[2][0] = 7.0;
  matrix.GetMatrix()[2][1] = 8.0;
  matrix.GetMatrix()[2][2] = 9.0;

  Matrix otherMatrix(3, 3);
  otherMatrix.GetMatrix()[0][0] = 2.0;
  otherMatrix.GetMatrix()[0][1] = 3.0;
  otherMatrix.GetMatrix()[0][2] = 4.0;
  otherMatrix.GetMatrix()[1][0] = 5.0;
  otherMatrix.GetMatrix()[1][1] = 6.0;
  otherMatrix.GetMatrix()[1][2] = 7.0;
  otherMatrix.GetMatrix()[2][0] = 8.0;
  otherMatrix.GetMatrix()[2][1] = 9.0;
  otherMatrix.GetMatrix()[2][2] = 10.0;

  Matrix originalMatrix = matrix;

  matrix -= otherMatrix;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix.GetMatrix()[i][j], originalMatrix.GetMatrix()[i][j] -
                                              otherMatrix.GetMatrix()[i][j]);
    }
  }
}

TEST(MatrixTest, MatrixMultiplicationScalarOperator) {
  Matrix matrix(2, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;

  Matrix originalMatrix = matrix;

  double scalar = 2.0;
  matrix *= scalar;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix(i, j), originalMatrix(i, j) * scalar);
    }
  }
}

TEST(MatrixTest, MatrixMultiplicationScalarOperator3x3) {
  Matrix matrix(3, 3);
  matrix.GetMatrix()[0][0] = 1.0;
  matrix.GetMatrix()[0][1] = 2.0;
  matrix.GetMatrix()[0][2] = 3.0;
  matrix.GetMatrix()[1][0] = 4.0;
  matrix.GetMatrix()[1][1] = 5.0;
  matrix.GetMatrix()[1][2] = 6.0;
  matrix.GetMatrix()[2][0] = 7.0;
  matrix.GetMatrix()[2][1] = 8.0;
  matrix.GetMatrix()[2][2] = 9.0;

  Matrix originalMatrix = matrix;

  double scalar = 2.0;
  matrix *= scalar;

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(matrix(i, j), originalMatrix(i, j) * scalar);
    }
  }
}

TEST(MatrixTest, EqualityOperator2x2) {
  Matrix matrix1(2, 2);
  matrix1.GetMatrix()[0][0] = 1.0;
  matrix1.GetMatrix()[0][1] = 2.0;
  matrix1.GetMatrix()[1][0] = 3.0;
  matrix1.GetMatrix()[1][1] = 4.0;

  Matrix matrix2(2, 2);
  matrix2.GetMatrix()[0][0] = 1.0;
  matrix2.GetMatrix()[0][1] = 2.0;
  matrix2.GetMatrix()[1][0] = 3.0;
  matrix2.GetMatrix()[1][1] = 4.0;

  EXPECT_TRUE(matrix1 == matrix2);

  matrix2.GetMatrix()[1][1] = 99.0;

  EXPECT_FALSE(matrix1 == matrix2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
