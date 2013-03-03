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

class IFunction {
public:
    virtual double value(Point point) const;
    virtual short dimensions() const;
};

#endif /* defined(__MOptimizer__IFunction__) */
