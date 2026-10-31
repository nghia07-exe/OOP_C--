#include <iostream>
#include <sstream>

#include "Fraction.h"

using namespace std;

int main() {
    cout << "=== 1. TEST INPUT / OUTPUT ===" << endl;
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;

    stringstream ss("8 10");
    Fraction f_in;
    ss >> f_in;
    cout << "f_in (nhap tu stream '8 10'): " << f_in << endl;

    cout << "\n=== 2. TEST (+, -, *, /) ===" << endl;
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;

    cout << "\n=== 3. TEST (>, <, ==, >=, <=, !=) ===" << endl;
    Fraction f3(2, 4);
    cout << f1 << " > " << f2 << "  : " << (f1 > f2) << endl;
    cout << f1 << " < " << f2 << "  : " << (f1 < f2) << endl;
    cout << f1 << " == " << f3 << " : " << (f1 == f3) << endl;
    cout << f1 << " != " << f2 << " : " << (f1 != f2) << endl;
    cout << f1 << " >= " << f3 << " : " << (f1 >= f3) << endl;
    cout << f1 << " <= " << f2 << " : " << (f1 <= f2) << endl;

    cout << "\n=== 4. TEST (=, +=, *=) ===" << endl;
    Fraction f_assign;
    f_assign = f1;
    cout << "f_assign = f1: " << f_assign << endl;

    f_assign += f2;
    cout << "f_assign += f2: " << f_assign << endl;

    f_assign *= Fraction(2, 3);
    cout << "f_assign *= 2/3: " << f_assign << endl;

    cout << "\n=== 5. TEST (++, --) ===" << endl;
    Fraction f_inc(1, 2);
    cout << "Ban dau: " << f_inc << endl;
    cout << "++f_inc (tien to): " << ++f_inc << " | Gia tri sau do: " << f_inc
         << endl;
    cout << "f_inc++ (hau to):  " << f_inc++ << " | Gia tri sau do: " << f_inc
         << endl;
    cout << "--f_inc (tien to): " << --f_inc << " | Gia tri sau do: " << f_inc
         << endl;
    cout << "f_inc-- (hau to):  " << f_inc-- << " | Gia tri sau do: " << f_inc
         << endl;

    cout << "\n=== 6. TEST (int, float) ===" << endl;
    Fraction f_cast(7, 2);
    cout << "f_cast: " << f_cast << endl;
    cout << "(int)f_cast: " << static_cast<int>(f_cast) << endl;
    cout << "(float)f_cast: " << static_cast<float>(f_cast) << endl;


    return 0;
}