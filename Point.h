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
    bool same(Point & P);
} ;

/*class col_Point {
    Point *tab;
    int nbp;
    int cap;
public :
    col_Point(Point *tab, int nbp, int cap);
};
*/
class Droite
{
    double a ;
    double b ;
public :
    Droite (double a=0.0, double b=0.0) ;
    Droite(Point & A, Point & B) ;
    void afficherDroite();
    bool pointBelong (Point & A);
    bool parallel (Droite & d);
    void tablePointBelong (Point *point_table, int &n);
} ;

#endif
