#include <iostream>

#include "Fraction.h"

int Fraction::count_ = 0;
int main() {
    Fraction::printCount();
    std::cout << "--- TEST BIEN TINH (STACK) ---\n";
    Fraction f1;         // 0/1
    Fraction f2(3, 4);   // 3/4
    Fraction f3(5);      // 5/1
    Fraction f4("777");  // 7/9
    Fraction f5(f2);     // 3/4 (copy tu f2)
    Fraction::printCount();

    std::cout << "f1 (mac dinh): ";
    f1.print();
    std::cout << "f2 (3, 4):     ";
    f2.print();
    std::cout << "f3 (5):        ";
    f3.print();
    std::cout << "f4 (\"7/9\"):    ";
    f4.print();
    std::cout << "f5 (copy f2):  ";
    f5.print();

    std::cout << "\n--- TEST CAP PHAT DONG (HEAP - new) ---\n";
    Fraction* pf1 = new Fraction();
    Fraction* pf2 = new Fraction(1, 2);
    Fraction* pf3 = new Fraction(10);
    Fraction* pf4 = new Fraction("12/25");
    Fraction* pf5 = new Fraction(*pf2);
    Fraction::printCount();

    std::cout << "pf1: ";
    pf1->print();
    std::cout << "pf2: ";
    pf2->print();
    std::cout << "pf3: ";
    pf3->print();
    std::cout << "pf4: ";
    pf4->print();
    std::cout << "pf5: ";
    pf5->print();

    std::cout << "Xoa pf1 -> pf5...\n";
    delete pf1;
    delete pf2;
    delete pf3;
    delete pf4;
    delete pf5;
    Fraction::printCount();

    return 0;
}