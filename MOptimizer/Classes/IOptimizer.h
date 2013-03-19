//
//  IOptimizer.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__IOptimizer__
#define __MOptimizer__IOptimizer__

#define MAX_ITER 25

class Point;
class IFunction;
class Matrix;

class IOptimizer {
    
protected:
    Matrix hessian(const IFunction &function, const Point &where, const Point &direction) const;
    Point gradient(const IFunction &f, const Point &where, const Point &direction) const;
    
    // Первая производная
    double derivative1(const IFunction &function, const Point &where, short dimension, const Point &direction) const;
    
public:
    virtual Point optimize(const IFunction &function, const Point &startPoint, const Point &direction, const double eps) const = 0;
};

#endif /* defined(__MOptimizer__IOptimizer__) */
