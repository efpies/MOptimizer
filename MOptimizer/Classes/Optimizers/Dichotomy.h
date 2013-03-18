//
//  Dichotomy.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 18.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Dichotomy__
#define __MOptimizer__Dichotomy__

#include "IOptimizer.h"

class Dichotomy : public virtual IOptimizer {
    
public:
    virtual Point optimize(const IFunction &function, const Point &startPoint, const Point &direction, const double eps) const;
};

#endif /* defined(__MOptimizer__Dichotomy__) */
