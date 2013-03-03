//
//  PointHelper.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "PointHelper.h"
#include <iostream>

Point PointHelper::inputPoint()
{
    short dims;
    cout << "Input dimensions count: ";
    cin >> dims;
    
    vector<double> pointCoords = vector<double>(dims);
    cout << "Input values:" << endl;
    short j = 1;
    for (vector<double>::iterator i = pointCoords.begin(); i != pointCoords.end(); ++i, ++j) {
        cout << j << ":\t";
        cin >> *i;
    }
    return Point(pointCoords);
}
