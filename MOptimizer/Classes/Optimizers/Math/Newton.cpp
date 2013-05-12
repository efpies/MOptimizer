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
    unsigned iter = 0;
    
    do {
        // Ньютоновское направление
        actualDirection = -(hessian(function, nextPoint, direction).inversed() * gradient(function, nextPoint, direction));
        
        cout << endl << "grad ";
        gradient(function, nextPoint, direction).print();
        cout << endl << "hess" <<endl;
        hessian(function, nextPoint, direction).inversed().print();
        cout << endl << endl;
        
        // Следующая точка
        nextPoint = nextPoint + actualDirection;
        actualDirection.print();
        cout << " | ";
        nextPoint.print();
        cout << " " << iter << endl;
        ++iter;
    } while (actualDirection.norm() > eps && iter < MAX_ITER);
    
    cout << endl << iter << " iteration(s)" << endl;
    return nextPoint;
}
