//
//  Func24.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func24.h"
#include "Point.h"
#include <cmath>

double Func24::value(const Point &point) const
{
    if (point.dimensions() != dimensions()) {
        throw new IFunction::DimensionException;
    }
    
    return SQ(point[1] - SQ(point[0])) + 100 * SQ(1 - SQ(point[0]));
}

short Func24::dimensions() const
{
    return 2;
}

string Func24::stringRepresentation() const
{
    return string("F = (x2 - x1^2)^2 + 100 * (1 - x1^2)^2");
}
