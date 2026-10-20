#include <iostream>

#include "header.h"

int main() {
    Point3D o_point;
    Point3D A(1.0, 1.0, 1.0);

    Point3D B(4.0, 5.0, 1.0);
    std::cout << A.distance(B) << "\n";
    A.move(4.0, 5.0, 10.0);
    A.rotate();
    std::cout << A.distance(B) << "\n";

    return 0;
}
