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

Point::Point(const unsigned short dimensions)
    : coords(vector<double>(dimensions))
{
    for (pointItr dim = coords.begin(); dim != coords.end(); ++dim) {
        (*dim) = 0;
    }
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

double& Point::operator[](const unsigned short i)
{
    return coords[i];
}

const double& Point::operator[](const unsigned short i) const
{
    return coords[i];
}

short Point::dimensions() const
{
    return coords.size();
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

double Point::norm() const
{
    double norm = 0;
    for (cPointItr i = coords.begin(); i != coords.end(); ++i) {
        norm += SQ(*i);
    }
    return norm;
}

double norm(const Point &first, const Point &second)
{
    return (second - first).norm();
}

#pragma mark - Арифметические операции
#pragma mark - Point и double

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

Point operator-(const Point &originalPoint)
{
    vector<double> originalCoords = originalPoint.coords;
    
    for (pointItr i = originalCoords.begin(); i != originalCoords.end(); ++i) {
        (*i) *= -1;
    }
    
    return Point(originalCoords);
}

#pragma mark - Point и point

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
