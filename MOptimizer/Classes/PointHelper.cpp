//
//  PointHelper.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "PointHelper.h"
#include <iostream>

Point PointHelper::inputPoint(const short dimensionsCount)
{
    short dims;
    
    if (dimensionsCount) {
        cout << "Dimensions count:\t" << dimensionsCount << endl;
        dims = dimensionsCount;
    }
    else {
        cout << "Input dimensions count: ";
        cin >> dims;
    }
    
    vector<double> pointCoords = vector<double>(dims);
    short j = 1;
    for (vector<double>::iterator i = pointCoords.begin(); i != pointCoords.end(); ++i, ++j) {
        cout << "\tx" << j << ":\t";
        cin >> *i;
    }
    return Point(pointCoords);
}
