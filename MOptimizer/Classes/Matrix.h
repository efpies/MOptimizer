//
//  Matrix.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Matrix__
#define __MOptimizer__Matrix__

#include <vector>
using namespace std;

class Point;

class Matrix {
    vector<vector<double>> coords;
    Matrix cofactors() const;   // Алгебраическое дополнение
    Matrix sliceExcluding(short row, short col) const;  // Матрица без строки row и столбца col
    double minor(short row, short col) const;   // Минор матрицы sliceExcluding
    
public:
    Matrix(short rows, short cols);
    
    Matrix transposed() const;
    Matrix inversed() const;
    
    short rows() const;
    short cols() const;
    double determinant() const;
    
    void print() const;
    
      vector<double> &operator[](const unsigned short idx);
const vector<double> &operator[](const unsigned short idx) const;
    
    friend Matrix operator*(const Matrix &matrix, double multiplier);
    friend Point operator*(const Matrix &matrix, const Point &multiplierVector);
    friend Matrix operator/(const Matrix &matrix, double divider);
};

#endif /* defined(__MOptimizer__Matrix__) */
