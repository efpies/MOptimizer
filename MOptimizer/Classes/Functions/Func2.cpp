//
//  Func2.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 18.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func2.h"

#include "Point.h"

#define SQ(x) (x) * (x)
#define QB(x) (x) * (x)

double Func2::value(const Point &point) const
{
    if (point.dimensions() != dimensions()) {
        throw new IFunction::DimensionException;
    }
    
    return SQ(point[0]) + 3 * SQ(point[1]) + 2 * point[0] * point[1];
}

short Func2::dimensions() const
{
    return 2;
}

string Func2::stringRepresentation() const
{
    return string("F = x1^2 + 3*x2^2 + 2*x1*x2");
}
