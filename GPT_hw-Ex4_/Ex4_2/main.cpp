#include <exception>
#include <iostream>

#include "Array.h"

int main() {
    try {
        Array a, b;
        std::cout << "Enter two arrays (length followed by elements for each):\n";
        if (!(std::cin >> a >> b)) {
            std::cerr << "Invalid array input.\n";
            return 1;
        }
        std::cout << "a = " << a << ", b = " << b << '\n';
        std::cout << "a + b = " << a + b << '\n';

        Array c;
        c = a;
        std::cout << "c = a: " << c << '\n';
        c += b;
        std::cout << "c += b: " << c << '\n';

        Array copy(c);
        if (copy.size() > 0) {
            std::cout << "copy[0] = " << copy[0] << '\n';
            copy[0] = 100;
        }
        std::cout << "After changing copy[0]: copy = " << copy
                  << ", c = " << c << '\n';

        int* data = static_cast<int*>(c);
        std::cout << "Elements through (int*)c:";
        for (int i = 0; i < c.size(); ++i) {
            std::cout << ' ' << data[i];
        }
        std::cout << '\n';

        c = c;
        std::cout << "Self-assignment c = c: " << c << '\n';
        c += c;
        std::cout << "Self-concatenation c += c: " << c << '\n';
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
