//
//  Dichotomy.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 18.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Dichotomy.h"
#include "IFunction.h"
#include "Point.h"
#include <iostream>

Point Dichotomy::optimize(const IFunction &f, const Point &start, const Point &direction, const double eps) const
{
    // Локализация минимума методом Свенна
    double borders[2];
    swann(f, start, direction, borders);
    
    // Дихотомия
    const double delta = 0.1 * eps;	// Константа различимости
    double  L,                      // Длина интервала [a; b]
            lambda, mju;            // Временные точки в середине интервала
    bool	condition;              // Условие на окончание поиска
    
    do {
        L  = norm(start.withAlpha(direction, borders[0]), start.withAlpha(direction, borders[1])); 	// Вычисление интервала
        
        // Смена временных точек
        lambda = (borders[LEFT_BORDER] + borders[RIGHT_BORDER] - delta) / 2.0;
        mju    = (borders[LEFT_BORDER] + borders[RIGHT_BORDER] + delta) / 2.0;
        
        // Выполняется ли условие на окончание поиска?
        condition = (L <= eps);
        if(!condition) {
            // Нет — двигаем границы
            if(f.value(start.withAlpha(direction, mju)) > f.value(start.withAlpha(direction, lambda))) {
                borders[RIGHT_BORDER] = mju;
            }
            else {
                borders[LEFT_BORDER] = lambda;
            }
        }
    }
    while(!condition);
    
    // Возвращаем аппроксимирующий минимум
    return start.withAlpha(direction, (borders[LEFT_BORDER] + borders[RIGHT_BORDER]) / 2.0);
}
