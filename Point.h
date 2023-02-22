#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    double x ;
    double y ;
public :
    Point(double x=0.0, double y=0.0);
    double distance(Point & P);
    void afficher();
    double getAbscisse();
    double getOrdonne();
    void same(Point & P);
} ;

#endif
