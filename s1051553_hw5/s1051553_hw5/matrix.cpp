//
//  matrix.cpp
//  s1051553_hw5
//
//  Created by Ip Kinkwan on 7/4/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include "matrix.hpp"
#include <cassert>
#include <iomanip>

Matrix::Matrix()//Constructs a matrix filled with zero elements.
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
    (*this)(i, j) = 0;
}
   
double& Matrix::operator()(int i, int j)//Accesses a matrix element.
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}

double Matrix::operator()(int i, int j) const//Accesses a matrix element.
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}
   

Matrix& Matrix::operator+=(const Matrix& right)//Computes the matrix sum.
{
   for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
        elements[i, j] = elements[i, j] + right.elements[i, j];
    return *this;
}

//Computes the matrix sum.
Matrix operator+(const Matrix& left, const Matrix& right)
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
       for (int j = 0; j < Matrix::COLUMNS; j++)
           result(i,j) = left(i,j) + right(i, j);
   return result;
}
   

Matrix operator*(const Matrix& left, const Matrix& right)//Computes the matrix product.
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
       for (int j = 0; j < Matrix::COLUMNS; j++)
           for (int k = 0; k < 3; k++)
               result(i, j) += left(i, k) * right(k, j);
   return result;
}
   
//Computes the scalar product of a scalar value and a matrix.
Matrix operator*(const Matrix& left, double right)
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
       for (int j = 0; j < Matrix::COLUMNS; j++)
           result(i, j) = left(i, j) * right;
   return result;
}
   

//Computes the scalar product of a matrix and a scalar value.
Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

//Prints a matrix to an output stream.
ostream& operator<<(ostream& left, const Matrix& right)
{
    for (int i = 0; i < Matrix::ROWS; i++){
        for (int j = 0; j < Matrix::COLUMNS; j++)
            left << right(i, j) << " ";
        left << endl;
    }
    return left;
}
