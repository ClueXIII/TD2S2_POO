#include "col_point.h"
#include "Point.h"
#include <iostream>
using namespace std;

col_Point::col_Point(int cap) {
    Point *new_point_table;
    new_point_table = new Point[cap];
    this -> tab = new_point_table;
    this -> cap = cap;
    this -> nbp = 0;
    cout << " -- collection construite avec succees ! -- " << endl;
}

col_Point::col_Point(Point *tab, int nbp, int cap) {
    this -> tab = tab;
    this -> cap = cap;
    this -> nbp = nbp;
    cout << " -- collection construite avec succees ! -- " << endl;

}

col_Point::~col_Point() {
    cout << " -- apel du destructeur --" << endl;
}

bool col_Point::present(Point &P) {
    for (int i = 0; i < this->nbp; i++) {
        if (this->tab[i].getAbscisse() == P.getAbscisse() && this->tab[i].getOrdonne() == P.getOrdonne()) return true;
    }
    return false;
}

bool col_Point::add_point(Point &P) {
    if (!(this->present(P)) && this->nbp < this -> cap) {
        this -> tab[this -> nbp] = P;
        this -> nbp ++;
        return true; //renvoie vrais si l'ajout a pu se faire
    } else return false; //renvoie faux si l'ajout n'est pas possible
}

bool col_Point::supprimer(Point &P) {
    if (this->present(P)) {
        nbp--;
        return true;
    }
    return false;
}

bool col_Point::ajouter_bis(Point &P) {
    if(!this->present(P)) {
        if (this->nbp < this->cap) {
            this->tab[this->nbp] = P;
            this->nbp ++;
        } else {
            col_Point new_col(this->cap*2);
            for (int i = 0; i < this->nbp; i++) {
                new_col.tab[i] = this->tab[i];
                new_col.nbp++;
            }
            new_col.tab[new_col.nbp] = P;
            new_col.nbp++;
            this -> tab = new_col.tab;
            this -> cap = new_col.cap;
            this -> nbp = new_col.nbp;
            cout << "Capacitee multiplie par deux (aloue dynamiquement)" << endl;
        }
        return true; //renvoie vrais si l'ajout a pu se faire
    } else {
        return false; //renvoie false si l'ajout n'est pas possible
    }
}

void col_Point::add_tab_in_col(Point *tableau, int nbe) {
    for (int i = 0; i < nbe; i ++) {
        this->ajouter_bis(tableau[i]);
    }
}

void col_Point::afficher_col() {
    for (int i = 0; i < this -> nbp; i ++) {
        cout << "Point " << i << " : (" << this -> tab[i].getAbscisse() << "," << this -> tab[i].getOrdonne() << ')' << endl;
    }
}

col_Point::col_Point(const col_Point &A) {
    col_Point new_col(A.cap);//on alloue de l'espace mémoire
    this->tab = new_col.tab; //on met this a cet espace mémoire
    this->nbp =  A.nbp;
    for (int i = 0; i < this->nbp; ++i) {
        this->tab[i] = A.tab[i];//on copie tout les membre de A un par un
    }
}

void col_Point::intersection(const col_Point &A, col_Point &B) {
    for (int i = 0; i < this -> nbp; i ++) {
        for (int j = 0; j < A.nbp; j ++) {
            if(this->tab[i].getAbscisse() == A.tab[j].getAbscisse() && this->tab[i].getOrdonne() == A.tab[j].getOrdonne()) {
                B.ajouter_bis(this->tab[i]);
            }
        }
    }
}

col_Point::col_Point(const col_Point &A, const col_Point &B) {
    col_Point new_col(A.cap+B.cap); //par défaut on définit la capacité elle aussi comme unions des deux collections
    this->tab = new_col.tab;//on met this a cet espace mémoire
    this->cap = new_col.cap;
    this->nbp = new_col.nbp;
    for (int i = 0; i < A.nbp; i ++) {
        this->ajouter_bis(A.tab[i]);
    }
    for (int i = 0; i < B.nbp; i ++) {
        this->ajouter_bis(B.tab[i]);
    }// on ajoute tout les points de col A, puis tout les points de col B (les points en double seront automatiquement supprimés)
}
