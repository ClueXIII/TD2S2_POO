#include "Point.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
    Point A(8,10), B(8,10);
    if (A.same(B)) cout << "Points identitiques" << endl;
    return 0;
}