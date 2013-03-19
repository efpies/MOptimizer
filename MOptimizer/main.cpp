//
//  main.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include <iostream>
#include "PointHelper.h"
#include "Func19.h"
#include "Func24.h"
#include "Newton.h"

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

IFunction *selectFunction()
{
    short decision;
    
    cout << "Select function:" << endl;
    
    Func19 *f19 = new Func19;
    cout << "\t(19)\t" << f19->stringRepresentation() << endl;
    Func24 *f24 = new Func24;
    cout << "\t(24)\t" << f24->stringRepresentation() << endl;

    do {
        cin >> decision;
        
        switch (decision) {
            case 19:
                return f19;
                
            case 24:
                return f24;
                
            default:
                cout << "Select one from above" << endl;
                break;
        }
    } while (true);
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
    IFunction *targetFunction = selectFunction();   // Выбор целевой функции
    
    Point startPoint = inputPoint(*targetFunction);   // Ввод стартовой точки
    Point direction = inputDirection(*targetFunction, true); // Направление принимаем за единичный вектор
    
    double precision = inputPrecision();    // Ввод точности
    
    Point min = Newton().optimize(*targetFunction, startPoint, direction, precision);
    
    cout << "Minimum is:\t";
    min.print(precision);
    cout << endl << "F(min) is:\t";
    cout << targetFunction->value(min);
    
    return 0;
}

