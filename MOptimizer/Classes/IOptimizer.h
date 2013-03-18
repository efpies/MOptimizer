//
//  IOptimizer.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__IOptimizer__
#define __MOptimizer__IOptimizer__

#define LEFT_BORDER 0
#define RIGHT_BORDER 1

class Point;
class IFunction;

class IOptimizer {
    
protected:
    void swann(const IFunction &function, const Point &startPoint, const Point &direction, double borders[2]) const;
    
public:
    virtual Point optimize(const IFunction &function, const Point &startPoint, const Point &direction, const double eps) const = 0;
};

#endif /* defined(__MOptimizer__IOptimizer__) */
