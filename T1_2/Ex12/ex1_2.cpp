#include "ex1_2.h"

#include <iostream>
#include <string>

int main() {
    int a[5] = {9, 8, -1, 4, 7};
    int b[4] = {-2, -9, 0, 4};

    Sort(a, 5, Ascending);
    Print(a, 5);

    Sort(b, 4, Descending);
    Print(b, 4);

    return 0;
}
