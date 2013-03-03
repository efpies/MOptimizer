//
//  IOptimizer.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__IOptimizer__
#define __MOptimizer__IOptimizer__

class Point;
class IFunction;

class IOptimizer {
public:
    virtual Point optimize(const IFunction &function) const;
};

#endif /* defined(__MOptimizer__IOptimizer__) */
