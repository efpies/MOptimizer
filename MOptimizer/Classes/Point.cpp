//
//  Point.cpp
//  MOptimizer
//
//  Created by Nicholas Yasnov on 03.03.13.
//  Copyright (c) 2013 efpies. All rights reserved.
//

#include "Point.h"

#include <iostream>
#include <cfloat>
#include <cmath>

#define SQ(x) (x) * (x)

typedef vector<double>::const_iterator cPointItr;
typedef vector<double>::iterator pointItr;

Point::Point(const Point &srcPoint)
    : coords(srcPoint.coords)
{
    
}

Point::Point(const vector<double> &_coords)
    : coords(_coords)
{
    
}

void Point::print(const double precision) const
{
    short savePrecision = cout.precision();
    short newPrecision = precision ? -log10(precision) : savePrecision;
    cout.precision(newPrecision);
    
    cout << "(";
    for (cPointItr i = coords.begin(); i != coords.end(); ++i) {
        if (i != coords.begin()) {
            cout << ", ";
        }
        
        cout << *i;
    }
    cout << ")";
    
    cout.precision(savePrecision);
}

double& Point::operator[](unsigned int i)
{
    return coords[i];
}

const double& Point::operator[](unsigned int i) const
{
    return coords[i];
}

short Point::dimensions() const
{
    return coords.size();
}

bool Point::isZero() const
{
    for (cPointItr i = coords.begin(); i != coords.end(); ++i) {
        if ((*i) == 0) {
            return true;
        }
    }
    
    return false;
}

Point Point::withAlpha(const Point &direction, const double alpha) const
{
    if (dimensions() != direction.dimensions()) {
        throw new Point::DimensionException();
    }
    
    Point newPoint = Point(*this);
    
    for (int i = 0; i < newPoint.dimensions(); ++i) {
        newPoint[i] += direction[i] * alpha;
    }
    
    return newPoint;
}

double norm(const Point &first, const Point &second)
{
    Point diff = second - first;
    double norm = 0;
    for (cPointItr i = diff.coords.begin(); i != diff.coords.end(); ++i) {
        norm += SQ(*i);
    }
    
    return sqrt(norm);
}

#pragma mark - Arithmetic operations
#pragma mark - Point and double

Point operator/(const Point &originalPoint, const double divider)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) = divider ? (*i) / divider : DBL_MAX;
    }
    
    return Point(originalCoords);
}

Point operator*(const Point &originalPoint, const double multiplier)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) *= multiplier;
    }
    
    return Point(originalCoords);
}

Point operator*(const double multiplier, const Point &originalPoint)
{
    return operator*(originalPoint, multiplier);
}

Point operator+(const Point &originalPoint, const double composed)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) += composed;
    }
    
    return Point(originalCoords);
}

Point operator+(const double composed, const Point &originalPoint)
{
    return operator+(originalPoint, composed);
}

Point operator-(const Point &originalPoint, const double subtracted)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) -= subtracted;
    }
    
    return Point(originalCoords);
}

Point operator*=(const Point &originalPoint, const double multiplier)
{
    return operator*(originalPoint, multiplier);
}

Point operator+=(const Point &originalPoint, const double composed)
{
    return operator+(originalPoint, composed);
}

Point operator-(const Point &originalPoint)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) *= -1;
    }
    
    return Point(originalCoords);
}

#pragma mark - Point and point

Point operator/(const Point &originalPoint, const Point &dividerPoint)
{
    if (originalPoint.dimensions() != dividerPoint.dimensions()) {
        throw new Point::DimensionException();
    }
    
    Point newPoint = Point(originalPoint);
    
    for (int i = 0; i < newPoint.dimensions(); ++i) {
        newPoint[i] = dividerPoint[i] ? newPoint[i] / dividerPoint[i] : DBL_MAX;
    }
    
    return newPoint;
}

Point operator*(const Point &originalPoint, const Point &multiplierPoint)
{
    if (originalPoint.dimensions() != multiplierPoint.dimensions()) {
        throw new Point::DimensionException();
    }
    
    Point newPoint = Point(originalPoint);
    
    for (int i = 0; i < newPoint.dimensions(); ++i) {
        newPoint[i] *= multiplierPoint[i];
    }
    
    return newPoint;
}

Point operator+(const Point &originalPoint, const Point &composedPoint)
{
    if (originalPoint.dimensions() != composedPoint.dimensions()) {
        throw new Point::DimensionException();
    }
    
    Point newPoint = Point(originalPoint);

    for (int i = 0; i < newPoint.dimensions(); ++i) {
        newPoint[i] += composedPoint[i];
    }
    
    return newPoint;
}

Point operator-(const Point &originalPoint, const Point &subtractedPoint)
{
    if (originalPoint.dimensions() != subtractedPoint.dimensions()) {
        throw new Point::DimensionException();
    }
    
    Point newPoint = Point(originalPoint);

    for (int i = 0; i < newPoint.dimensions(); ++i) {
        newPoint[i] -= subtractedPoint[i];
    }
    
    return newPoint;
}

Point operator*=(const Point &originalPoint, const Point &multiplierPoint)
{
    return operator*(originalPoint, multiplierPoint);
}

Point operator+=(const Point &originalPoint, const Point &composedPoint)
{
    return operator+(originalPoint, composedPoint);
}

bool operator==(const Point &first, const Point &second)
{
    if (first.dimensions() != second.dimensions()) {
        throw new Point::DimensionException();
    }
    
    for (int i = 0; i < first.dimensions(); ++i) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    
    return true;
}

bool operator!=(const Point &first, const Point &second)
{
    if (first.dimensions() != second.dimensions()) {
        throw new Point::DimensionException();
    }
    
    for (int i = 0; i < first.dimensions(); ++i) {
        if (first[i] == second[i]) {
            return false;
        }
    }
    
    return true;
}

#pragma mark - cmath

Point fabs(const Point &originalPoint)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) = fabs(*i);
    }
    
    return Point(originalCoords);
}
