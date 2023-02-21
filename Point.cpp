#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point(double x, double y) {
    this -> x = x;
    this -> y = y;
}

void Point::afficher() {
    cout << '(' << x << ", " << y << ')';
}

double Point::distance(Point & P) {
    double d1 = this->x - P.x;
    d1*=d1;
    double d2 = this->y - P.y;
    d2*=d2;
    return (sqrt(d1 + d2));
}

double Point::getAbscisse() {
    return (this->x);
}

double Point::getOrdonne() {
    return (this->y);
}

bool Point::same(Point & P) {
    if (distance(P) < 0.0001) {
        return true;
    } else {
        return false;
    }
}

Droite::Droite(double a, double b) {
    this -> a = a;
    this -> b = b;
}

Droite::Droite(Point &A, Point &B) {
    this -> a = (B.getOrdonne() - A.getOrdonne())/(B.getAbscisse()-A.getAbscisse());
    this -> b = A.getOrdonne()-((this -> a)*A.getAbscisse());
}

void Droite::afficherDroite() {
    cout << this -> a << "x + " << this -> b << endl;
}

bool Droite::pointBelong(Point &A) {
    if(A.getOrdonne() == (this -> a * A.getAbscisse()) + this->b){
        return true;
    } else {
        return false;
    }
}

bool Droite::parallel(Droite & d) {
    if (this -> a == d.a){
        return true;
    }else{
        return false;
    }
}

void Droite::tablePointBelong(Point *point_table, int &n) {
    int N = 0;
    Point *new_point_table;
    new_point_table = new Point[n];
    for (int i = 0; i < n; i++) {
        if (this->pointBelong(point_table[i])){
            new_point_table[N] = point_table[i];
            N++;
        }
    }
    n = N;
    point_table = new_point_table;
}

col_Point::col_Point(int cap) {
    Point *new_point_table;
    new_point_table = new Point[cap];
    this -> tab = new_point_table;
    this -> cap = cap;
    this -> nbp = 0;
}

col_Point::col_Point(Point *tab, int nbp, int cap) {
    this -> tab = tab;
    this -> cap = cap;
    this -> nbp = nbp;
}

col_Point::~col_Point() {
    cout << " -- apel du destructeur --" << endl;
}

bool col_Point::present(Point &P) {
    for (int i = 0; i <= this->nbp; i++) {
        if (this->tab[i].getAbscisse() == P.getAbscisse() && this->tab[i].getOrdonne() == P.getOrdonne()) return true;
    }
    return false;
}

bool col_Point::add_point(Point &P) {
    if (!(this->present(P)) && this->nbp < this -> cap) {
        this -> tab[this -> nbp] = P;
        return true; //renvoie vrais si l'ajout a pu se faire
    } else {return false;} //renvoie faut si l'ajout n'est pas possible
}

bool col_Point::supprimer(Point &P) {
    if (this->present(P)) {
        nbp--;

        return true;
    }
    return false;
}
