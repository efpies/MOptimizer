//
//  Func1.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Func1.h"

#include "Point.h"

#define F(x) (x)*(x) + 3*(x) - 4

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
