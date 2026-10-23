#include <exception>
#include <iostream>

#include "Fraction.h"

int main() {
    Fraction a, b;
    std::cout << "Enter two fractions (numerator denominator for each):\n";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Invalid fraction input.\n";
        return 1;
    }

    try {
        std::cout << "a = " << a << ", b = " << b << '\n';
        std::cout << "a + b = " << a + b << '\n';
        std::cout << "a - b = " << a - b << '\n';
        std::cout << "a * b = " << a * b << '\n';
        if (b != Fraction(0)) {
            std::cout << "a / b = " << a / b << '\n';
        } else {
            std::cout << "a / b is undefined (b is zero).\n";
        }

        std::cout << std::boolalpha;
        std::cout << "a > b: " << (a > b) << '\n';
        std::cout << "a < b: " << (a < b) << '\n';
        std::cout << "a == b: " << (a == b) << '\n';
        std::cout << "a >= b: " << (a >= b) << '\n';
        std::cout << "a <= b: " << (a <= b) << '\n';
        std::cout << "a != b: " << (a != b) << '\n';

        Fraction c;
        c = a;
        std::cout << "c = a: " << c << '\n';
        c += b;
        std::cout << "c += b: " << c << '\n';
        c *= b;
        std::cout << "c *= b: " << c << '\n';

        c = a;
        std::cout << "++c: " << ++c << '\n';
        Fraction previous = c++;
        std::cout << "c++ returns " << previous << ", c = " << c << '\n';
        std::cout << "--c: " << --c << '\n';
        previous = c--;
        std::cout << "c-- returns " << previous << ", c = " << c << '\n';
        std::cout << "(float)a = " << static_cast<float>(a) << '\n';
        std::cout << "(int)a = " << static_cast<int>(a) << '\n';
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
