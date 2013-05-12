//
//  Newton.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 19.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Newton__
#define __MOptimizer__Newton__

#include "IOptimizer.h"

class Newton : public virtual IOptimizer {
    
public:
    virtual Point optimize(const IFunction &function, const Point &startPoint, const Point &direction, const double eps) const;
};

#endif /* defined(__MOptimizer__Newton__) */
