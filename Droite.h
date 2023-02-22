#ifndef TD2S2_POO_DROITE_H
#define TD2S2_POO_DROITE_H
#include "Point.h"


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
