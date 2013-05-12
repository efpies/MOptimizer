//
//  Func20.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 26.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Func20__
#define __MOptimizer__Func20__

#include "IFunction.h"

class Func20 : public IFunction {
public:
    double value(const Point &point) const;
    short dimensions() const;
    string stringRepresentation() const;
};

#endif /* defined(__MOptimizer__Func20__) */
