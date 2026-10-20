#include "ex1_1.h"

#include <iostream>
#include <string>

int main() {
    int a[5] = {9, 8, -1, 4, 7};
    float b[6] = {0.0, 0.99, -9.67, 6.7, -3.6, 1.0};
    char c[7] = {'1', '0', 'd', '~', 'O', 'O', 'P'};
    std::string d[4] = {"me", "Don't", "Like", " HCMUS"};

    Sort(a, 5);
    Print(a, 5);

    Sort(b, 6);
    Print(b, 6);

    Sort(c, 7);
    Print(c, 7);

    Sort(d, 4);
    Print(d, 4);
    return 0;
}
