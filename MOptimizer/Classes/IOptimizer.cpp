//
//  IOptimizer.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "IOptimizer.h"
#include "Point.h"
#include "IFunction.h"
#include <iostream>

#define STEP 0.01

void IOptimizer::swann(const IFunction &f, const Point &start, const Point &direction, double borders[2]) const
{
    // Определим шаг
    double step = STEP;
    double alpha;
	step = (f.value(start + step) > f.value(start)) ? -step : step;
	alpha = step;
    
	while(f.value(start.withAlpha(direction, alpha + 2 * step)) < f.value(start.withAlpha(direction, alpha))) {
		step *= 2;
		alpha += step;
	}
    
	// Начальные границы локализации минимума
	borders[LEFT_BORDER] = min(alpha + 2 * step, alpha - step);
	borders[RIGHT_BORDER] = max(alpha + 2 * step, alpha - step);
    
    cout << endl << "Localization area:\t";
    start.withAlpha(direction, borders[LEFT_BORDER]).print();
    cout << " ; ";
    start.withAlpha(direction, borders[RIGHT_BORDER]).print();
    cout << endl;
}
