#include "ex1_3.h"

#include <iostream>
#include <string>

void solveCQ();
int main() {
    int a[5] = {19, 28, -12, 24, 7};
    float b[6] = {7.0, -1.99, -6.67, 9.7, -3.88, 1.99};
    char c[7] = {'x', 'z', 'Y', '~', '0', 'O', 'y'};
    std::string d[4] = {"i", " Homework", "Like", " OOP"};

    Sort(a, 5, Ascending<int>);
    Print(a, 5);

    Sort(b, 6, Descending<float>);
    Print(b, 6);

    Sort(c, 7, Ascending<char>);
    Print(c, 7);

    Sort(d, 4, Descending<std::string>);
    Print(d, 4);

    return 0;
}
