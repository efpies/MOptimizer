//
//  IFunction.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__IFunction__
#define __MOptimizer__IFunction__

class Point;

#define SQ(x) ((x) * (x))
#define QB(x) ((x) * (x) * (x))

#include <string>
using namespace std;

class IFunction {
public:
    class DimensionException {
    public:
        DimensionException() { }
    };
    
    virtual double value(const Point &point) const = 0;
    virtual short dimensions() const = 0;
    virtual string stringRepresentation() const = 0;
};

#endif /* defined(__MOptimizer__IFunction__) */
