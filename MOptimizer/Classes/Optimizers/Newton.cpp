//
//  Newton.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Newton.h"
#include "IFunction.h"
#include "Point.h"
#include "Matrix.h"
#include <iostream>

Point Newton::optimize(const IFunction &function, const Point &startPoint, const Point &direction, const double eps) const
{
    Point nextPoint = startPoint;
    Point actualDirection = direction;
    
    do {
        actualDirection = - (hessian(function, nextPoint, direction).inversed() * gradient(function, nextPoint, direction));
        nextPoint = nextPoint + actualDirection;
    } while (actualDirection.norm() > eps);
    
    return nextPoint;
}
