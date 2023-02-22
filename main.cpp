#include "Point.h"
#include "Droite.h"
#include "col_point.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
    cout << "-- Afin de simplifier l'affichage des resultats je vais plusieurs fois utiliser la fonction afficher_col que j'ai ajoute --" << endl;
cout << "-------------------------------------0-------------------------------------" << endl;
    Point A(8,10), B(8,10), C(9,5),D(10,8), E(4,8), F(1,0), G(4,6);//construction des points
    (A.same(B));//cout points identiques si la distance entre les points est inférieure a 0.0001
    (A.same(C));//cout points distincs si la distance entre les points est inférieure a 0.0001)
cout << "-------------------------------------1-------------------------------------" << endl;
    col_Point colA;//on test le constructeur
cout << "-------------------------------------2-------------------------------------" << endl;
    Point *point_table;//on crée le tableau de points pour le test
    int n = 3;//nombres d'éléments du tableau
    point_table = new Point[n];
    point_table[0] = A;
    point_table[1] = B;
    point_table[2] = C;
    col_Point colB(point_table, n);//on test le constructeur
    colB.afficher_col();
cout << "-------------------------------------3-------------------------------------" << endl;
    //voir class col_Point dans point.h
cout << "-------------------------------------4-------------------------------------" << endl;
    colB.present(A) ? cout << "le point est present dans la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    colB.present(D) ? cout << "le point est present dans la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    cout << endl;
cout << "-------------------------------------5-------------------------------------" << endl;
    colA.add_point(A) ? cout << "le point est ajoute a la collection" << endl : cout << "le point est deja dans la collection" << endl;
    colA.add_point(A) ? cout << "le point est ajoute a la collection" << endl : cout << "le point est deja dans la collection" << endl;
    colA.afficher_col();
    //la seconde fois, le code dis que le point est déja dans la collection
cout << "-------------------------------------6-------------------------------------" << endl;
    colA.supprimer(C) ? cout << "le point est supprime de la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    //renvoie false car le point C n'est pas présent dans la collection
    colA.supprimer(A) ? cout << "le point est supprime de la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    //renvoie true car le point A est dans la collection
cout << "-------------------------------------7-------------------------------------" << endl;
    col_Point colC(2);//on créer une nouvelle collection avec une capacitée de 2
    //on y ajoute 3 point
    colC.ajouter_bis(F);
    colC.ajouter_bis(G);
    colC.ajouter_bis(E);//capacitée multiplié par deux
    //destructeur apellé automatiquement
    colC.afficher_col();
cout << "-------------------------------------8-------------------------------------" << endl;
    colC.add_tab_in_col(point_table, n);
    colC.afficher_col();//on constate que seulement 2 point sur 3 sont ajouté car le point A est le même que le B, il n'est donc pas ajouté deux fois;
    return 0;
}