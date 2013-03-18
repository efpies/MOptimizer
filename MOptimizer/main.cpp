//
//  main.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include <iostream>
#include "Point.h"
#include "PointHelper.h"
#include "Func1.h"

Point inputPoint(const IFunction &f)
{
    cout << "-- Input start point --" << endl;
    return PointHelper::inputPoint(f.dimensions());
}

int main(int argc, const char * argv[])
{
    Func2 f = Func2();
    cout << f.stringPresentation() << endl << endl;
    
    Point p = inputPoint(f);
    return 0;
}

