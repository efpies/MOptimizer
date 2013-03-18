//
//  Func2.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 18.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Func2__
#define __MOptimizer__Func2__

#include "IFunction.h"

class Func2 : public IFunction {
public:
    double value(const Point &point) const;
    short dimensions() const;
    string stringRepresentation() const;
};

#endif /* defined(__MOptimizer__Func2__) */
