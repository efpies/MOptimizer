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

int main(int argc, const char * argv[])
{
    Point p = PointHelper::inputPoint();
    p.print();
    return 0;
}

