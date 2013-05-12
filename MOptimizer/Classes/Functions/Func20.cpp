//
//  Func20.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 26.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func20.h"
#include "Point.h"
#include <cmath>

double Func20::value(const Point &point) const
{
    if (point.dimensions() != dimensions()) {
        throw new IFunction::DimensionException;
    }
    return pow(point[0] + 1, 2) + pow(point[1] - 3, 2) + 4 * pow(point[2] + 5, 2);
}

short Func20::dimensions() const
{
    return 3;
}

string Func20::stringRepresentation() const
{
    return string("F = (x2 - x1^2)^2 + 100 * (1 - x1^2)^2");
}