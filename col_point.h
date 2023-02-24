#ifndef TD2S2_POO_COL_POINT_H
#define TD2S2_POO_COL_POINT_H
#include "Point.h"

class col_Point {
    Point *tab;
    int nbp;
    int cap;
public :
    col_Point(int cap=100);
    col_Point(Point *tab, int nbp, int cap=100); //comment faire sans avoir a mettre le nbe en paramétre
    col_Point(const col_Point &A);
    col_Point(const col_Point &A, const col_Point &B);
    void afficher_col();
    bool present(Point & P);
    bool add_point(Point & P);
    bool supprimer(Point & P);
    bool ajouter_bis(Point & P);
    void add_tab_in_col(Point *tab, int nbe);
    void intersection(const col_Point &A, col_Point &B);
    void col_stats();
    ~col_Point();
};

#endif
