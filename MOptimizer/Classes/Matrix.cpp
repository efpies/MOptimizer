//
//  Matrix.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Matrix.h"
#include <iostream>
#include <cfloat>
#include "Point.h"

typedef vector<vector<double>>::iterator rowIterator;
typedef vector<vector<double>>::const_iterator cRowIterator;
typedef vector<double>::iterator colIterator;
typedef vector<double>::const_iterator cColIterator;

Matrix::Matrix(short rows, short cols)
{
    coords = vector<vector<double>>(rows);
    for (rowIterator row = coords.begin(); row != coords.end(); ++row) {
        (*row) = vector<double>(cols);
        
        for (colIterator col = (*row).begin(); col != (*row).end(); ++col) {
            (*col) = arc4random() % 9;
        }
    }
}

void Matrix::print() const
{
    cout << "Matrix:";
    for (cRowIterator row = coords.begin(); row != coords.end(); ++row) {
        cout << endl << "\t";
        for (cColIterator col = (*row).begin(); col != (*row).end(); ++col) {
            cout << " " << *col;
        }
    }
}

short Matrix::rows() const
{
    return coords.size();
}

short Matrix::cols() const
{
    return coords[0].size();
}

Matrix Matrix::sliceExcluding(short exRow, short exCol) const
{
    Matrix slice = Matrix(rows() - 1, cols() - 1);
    for (short row = 0, actualRow = 0; row < rows(); ++row) {
        for (short col = 0, actualCol = 0; col < cols(); ++col) {
            if (row != exRow && col != exCol) {
                slice[actualRow][actualCol] = (*this)[row][col];
                ++actualCol;
            }
        }
        actualRow += (row != exRow) ? 1 : 0;
    }
    return slice;
}

Matrix Matrix::transposed() const
{
    Matrix transposed = Matrix(cols(), rows());
    for (short rowIdx = 0; rowIdx < rows(); ++rowIdx) {
        for (short colIdx = 0; colIdx < cols(); ++colIdx) {
            transposed[colIdx][rowIdx] = (*this)[rowIdx][colIdx];
        }
    }
    return transposed;
}

double Matrix::minor(short row, short col) const
{
    return sliceExcluding(row, col).determinant();
}

Matrix Matrix::cofactors() const
{
    Matrix cofactors = Matrix(rows(), cols());
    for (short rowIdx = 0; rowIdx < rows(); ++rowIdx) {
        for (short colIdx = 0; colIdx < cols(); ++colIdx) {
            cofactors[rowIdx][colIdx] = minor(rowIdx, colIdx);
            cofactors[rowIdx][colIdx] *= ((rowIdx + colIdx) & 1) ? -1 : 1;
        }
    }
    return cofactors;
}

Matrix Matrix::inversed() const
{
    return cofactors().transposed() / determinant();
}

double Matrix::determinant() const
{
    if (rows() == 2 && cols() == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1];
    }
    else {
        vector<double> firstRow = (*this)[0];
        bool isPositive = true;
        double determinant = 0;

        for (short colIdx = 0; colIdx != cols(); ++colIdx, isPositive = !isPositive) {
            double minorDeterminant = firstRow[colIdx] * minor(0, colIdx);
            determinant += isPositive ? minorDeterminant : -minorDeterminant;
        }
        
        return determinant;
    }
}

vector<double> &Matrix::operator[](const unsigned short idx)
{
    return coords[idx];
}

const vector<double> &Matrix::operator[](const unsigned short idx) const
{
    return coords[idx];
}

#pragma mark - Арифметические операции

Matrix operator*(const Matrix &matrix, double multiplier)
{
    Matrix multiplied = Matrix(matrix.rows(), matrix.cols());
    for (short row = 0; row < matrix.rows(); ++row) {
        for (short col = 0; col < matrix.cols(); ++col) {
            multiplied[row][col] = matrix[row][col] * multiplier;
        }
    }
    return multiplied;
}

Point operator*(const Matrix &matrix, const Point &multiplierVector)
{
    Point multiplied = Point(matrix.rows());
    for (short row = 0; row < matrix.rows(); ++row) {
        for (short col = 0; col < matrix.cols(); ++col) {
            multiplied[row] += matrix[row][col] * multiplierVector[col];
        }
    }
    return multiplied;
}

Matrix operator/(const Matrix &matrix, double divider)
{
    Matrix divided = Matrix(matrix.rows(), matrix.cols());
    for (short row = 0; row < matrix.rows(); ++row) {
        for (short col = 0; col < matrix.cols(); ++col) {
            divided[row][col] = divider ? matrix[row][col] / divider : DBL_MAX;
        }
    }
    return divided;
}
