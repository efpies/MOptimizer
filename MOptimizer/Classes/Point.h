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
    class DimensionException {
    public:
        DimensionException() { }
    };
    
    Point(const Point &srcPoint);
    Point(const vector<double> &coords);
    Point(const unsigned short dimensions);
    
    void print(const double precision = 0) const;
    short dimensions() const;
    
    // Точка по направлению direction на расстоянии alpha
    Point withAlpha(const Point &direction, const double alpha) const;
    
    friend double norm(const Point &first, const Point &second);
           double norm() const;
    
    double& operator[](const unsigned short i);
	const double& operator[](const unsigned short i) const;
    
#pragma mark - Арифметические операции
#pragma mark - Point и double
    
    friend Point operator/(const Point &originalPoint, const double divider);
    friend Point operator*(const Point &originalPoint, const double multiplier);
    friend Point operator*(const double multiplier, const Point &originalPoint);
    friend Point operator+(const Point &originalPoint, const double composed);
    friend Point operator+(const double composed, const Point &originalPoint);
    friend Point operator-(const Point &originalPoint, const double subtracted);
    
    friend Point operator-(const Point &originalPoint);
    
#pragma mark - Point и point
    
    friend Point operator/(const Point &originalPoint, const Point &dividerPoint);
    friend Point operator*(const Point &originalPoint, const Point &multiplierPoint);
    friend Point operator+(const Point &originalPoint, const Point &composedPoint);
    friend Point operator-(const Point &originalPoint, const Point &subtractedPoint);
    
    friend bool operator==(const Point &first, const Point &second);
    friend bool operator!=(const Point &first, const Point &second);
    
#pragma mark - cmath
    
    friend Point fabs(const Point &originalPoint);
};

#endif /* defined(__MOptimizer__Point__) */
