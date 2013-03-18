//
//  Func1.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Func1__
#define __MOptimizer__Func1__

#include "IFunction.h"

class Func1 : public IFunction {
public:
    double value(const Point &point) const;
    short dimensions() const;
    string stringRepresentation() const;
};

#endif /* defined(__MOptimizer__Func1__) */
