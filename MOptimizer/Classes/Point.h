//
//  Point.h
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#ifndef __MOptimizer__Point__
#define __MOptimizer__Point__

#include <vector>
using namespace std;

class Point {
private:
    vector<double> coords;
    
public:
    Point(const Point &srcPoint);
    Point(const vector<double> &coords);
    
          double& operator[](unsigned int i);
	const double& operator[](unsigned int i) const;
    
    void print() const;
    short dimensions() const;
};

#endif /* defined(__MOptimizer__Point__) */
