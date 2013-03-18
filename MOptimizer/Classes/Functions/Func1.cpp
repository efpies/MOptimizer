//
//  Func1.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func1.h"

#include "Point.h"

#define F(x) (x)*(x) + 2*(x)

double Func1::value(const Point &point) const
{
    if (point.dimensions() != dimensions()) {
        throw new IFunction::DimensionException;
    }
    
    return F(point[0]);
}

short Func1::dimensions() const
{
    return 1;
}

string Func1::stringPresentation() const
{
    return string("F = x^2 + 2*x");
}
