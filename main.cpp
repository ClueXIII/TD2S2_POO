#include "Point.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
 //-------------------------------------/0\-------------------------------------
    Point A(8,10), B(8,10), C(9,5);//construction des points
    if (A.same(B)) cout << "Points identitiques" << endl;//cout point identique si la distance entre les points est inférieure a 0.0001
    cout << endl;
//-------------------------------------/1\-------------------------------------
    col_Point colA;//on test le constructeur
//-------------------------------------/2\-------------------------------------
    Point *point_table;//on crée le tableau de points pour le test
    point_table = new Point[3];
    point_table[0] = A;
    point_table[1] = B;
    point_table[2] = C;
    col_Point colB(point_table, 3);//on test le constructeur
    cout << endl;
//-------------------------------------/3\-------------------------------------
    //voir class col_Point dans point.h
//-------------------------------------/4\-------------------------------------
    colB.present(A) ? cout << "le point est present dans la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    cout << endl;
//-------------------------------------/5\-------------------------------------
    colA.add_point(A) ? cout << "le point est ajoute a la collection" << endl : cout << "le point est deja dans la collection" << endl;
    colA.add_point(A) ? cout << "le point est ajoute a la collection" << endl : cout << "le point est deja dans la collection" << endl;
    //la seconde fois, le code dis que le point est déja dans la collection
    cout << endl;
//-------------------------------------/6\-------------------------------------
    colA.supprimer(C) ? cout << "le point est supprime dans la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    //renvoie false car le point C n'est pas présent dans la collection
    colA.supprimer(A) ? cout << "le point est supprime dans la collection" << endl : cout << "le point n'est pas present dans la collection" << endl;
    //renvoie true car le point A est dans la collection
    cout << endl;
//-------------------------------------/7\-------------------------------------
    return 0;
}