//
//  IOptimizer.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "IOptimizer.h"
#include "Point.h"
#include "IFunction.h"
#include "Matrix.h"
#define STEP 0.0001

double IOptimizer::derivative1(const IFunction &f, const Point &x, short dimension, const Point &direction) const
{
    Point actualDirection = Point(direction);
    for (int iDimension = 0; iDimension < direction.dimensions(); ++iDimension) {
        actualDirection[iDimension] *= (iDimension == dimension) ? 1 : 0;
    }
    return (f.value(x.withAlpha(actualDirection, STEP)) - f.value(x.withAlpha(actualDirection, -STEP))) / (2.0 * STEP);
}


Matrix IOptimizer::hessian(const IFunction &f, const Point &x, const Point &direction) const
{
    Matrix hessian = Matrix(f.dimensions(), f.dimensions());
    for (short row = 0; row < hessian.rows(); ++row) {
        for (short col = 0; col < hessian.cols(); ++col) {
            // Выбор орт
            Point rowColDirection = Point(f.dimensions());
            rowColDirection[row] += direction[row];
            rowColDirection[col] += direction[col];
            
            Point rowDirection = Point(f.dimensions());
            rowDirection[row] += direction[row];
            
            Point colDirection = Point(f.dimensions());
            colDirection[col] += direction[col];
            
            hessian[row][col] = (f.value(x.withAlpha(rowColDirection, STEP)) - f.value(x.withAlpha(rowDirection, STEP)) - f.value(x.withAlpha(colDirection, STEP)) + f.value(x)) / SQ(STEP);
        }
    }
    return hessian;
}

Point IOptimizer::gradient(const IFunction &f, const Point &x, const Point &direction) const
{
    Point gradient = Point(f.dimensions());
    for (short dim = 0; dim < f.dimensions(); ++dim) {
        gradient[dim] = derivative1(f, x, dim, direction);
    }
    return gradient;
}
