//
//  Point.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Point.h"

#include <iostream>

typedef vector<double>::const_iterator pointItr;



Point::Point(const vector<double> &_coords)
    : coords(_coords)
{
    
}

void Point::print() const
{
    cout << "(";
    for (pointItr i = coords.begin(); i != coords.end(); ++i) {
        if (i != coords.begin()) {
            cout << ", ";
        }
        
        cout << *i;
    }
    cout << ")";
}

double& Point::operator[](unsigned int i)
{
    return coords[i];
}

const double& Point::operator[](unsigned int i) const
{
    return coords[i];
}
