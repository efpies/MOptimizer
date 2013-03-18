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
#include "Func2.h"
#include "Dichotomy.h"

Point inputPoint(const IFunction &f)
{
    cout << "-- Input start point --" << endl;
    return PointHelper::inputPoint(f.dimensions());
}

Point inputDirection(const IFunction &f, bool assume1 = false)
{
    if (f.dimensions() > 1 && !assume1) {
        cout << "-- Input direction --" << endl;
        return PointHelper::inputPoint(f.dimensions());
    }
    else {
        vector<double> start = vector<double>(f.dimensions());
        for (vector<double>::iterator i = start.begin(); i != start.end(); ++i) {
            (*i) = 1;
        }
        return Point(start);
    }
}

double inputPrecision()
{
    double precision;
    cout << "-- Input precision --" << endl;
    cin >> precision;
    return precision;
}

int main(int argc, const char * argv[])
{
    Func2 f = Func2();
    cout << f.stringPresentation() << endl << endl;
    
    Point p = inputPoint(f);
    Point d = inputDirection(f);
    
    double precision= inputPrecision();
    
    Dichotomy opt = Dichotomy();
    Point min = opt.optimize(f, p, d, precision);
    
    cout << "Minimum is:\t";
    min.print(precision);
    cout << endl << "F(min) is:\t";
    cout << f.value(min);
    
    return 0;
}

