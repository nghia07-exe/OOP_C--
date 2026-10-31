#include <iostream>
#include <string>

#include "Array.h"

int main() {
    int raw_int[] = {1, 2, 3, 4, 5};
    std::cout << "  Int array:\n";
    Array<int> arr_int(raw_int, 5);
    arr_int.print();

    Array<int> arr_copy(arr_int);
    std::cout << "  Copy int array:\n";
    arr_copy.print();

    float raw_float[] = {1.5f, 2.25f, 3.75f};
    Array<float> arr_float(raw_float, 3);
    std::cout << "  Float array:\n";
    arr_float.print();

    Array<double> arr_default(6);
    std::cout << "  Double array (default value):\n";
    arr_default.print();

    char raw_char[] = {'H', 'C', 'M', 'U', 'S'};
    Array<char> arr_char(raw_char, 5);
    std::cout << "  Char array:\n";
    arr_char.print();

    std::string raw_string[] = {"C++", "hoc", "O", "O", "P"};
    Array<std::string> arr_str(raw_string, 5);
    std::cout << "  String array:\n";
    arr_str.print();

    return 0;
}