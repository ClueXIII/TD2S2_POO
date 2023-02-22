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

void Point::same(Point & P) {
    if (distance(P) < 0.0001) {
        cout << "Points identitiques" << endl;
    } else {
        cout << "Points distincs" << endl;
    }
}

