//
//  Func19.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func19.h"
#include "Point.h"
#include <cmath>

double Func19::value(const Point &point) const
{
    if (point.dimensions() != dimensions()) {
        throw new IFunction::DimensionException;
    }
    
    return 100 * SQ(point[1] - SQ(point[0])) + SQ(1 - point[0]);
}

short Func19::dimensions() const
{
    return 2;
}

string Func19::stringRepresentation() const
{
    return string("F = 100 * (x2 - x1^2)^2 + (1 - x1)^2");
}
