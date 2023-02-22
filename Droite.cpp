#include "Droite.h"
#include <iostream>
using namespace std;

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
