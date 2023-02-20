#include "Point.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
 //-------------------------------------/0\-------------------------------------
    Point A(8,10), B(8,10), C(9,5);//construction des points
    if (A.same(B)) cout << "Points identitiques" << endl;//cout point identique si la distance entre les points est inférieure a 0.0001
//-------------------------------------/1\-------------------------------------
    col_Point colA;//on test le constructeur
//-------------------------------------/2\-------------------------------------
    Point *point_table;//on crée le tableau de points pour le test
    point_table = new Point[3];
    point_table[0] = A;
    point_table[1] = B;
    point_table[2] = C;
    col_Point colB(point_table, 3);//on test le constructeur
//-------------------------------------/3\-------------------------------------
    //voir class col_Point dans point.h
//-------------------------------------/4\-------------------------------------
    if (colB.present(A)) cout << "le point est present dans la collection" << endl;//cout sir le point est présent dans la collection

    return 0;
}