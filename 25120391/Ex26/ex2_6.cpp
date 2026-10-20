#include <iostream>

#include "array_of_int.h"

int main() {
    Array arr_of_int;
    // arr_of_int.Input();
    arr_of_int.Output();

    int size = arr_of_int.GetSize();
    std::cout << "Size of Array: " << size << "\n\n";
    arr_of_int.SetSize(size + 1);
    std::cout << "Update size success!\n";
    arr_of_int.Output();

    int specific_index = size;
    int out_of_range_value = arr_of_int.GetElement(specific_index);
    std::cout << "Out of range value in index " << specific_index << " :"
              << out_of_range_value << "\n\n";

    arr_of_int.SetElement(6, specific_index);
    std::cout << "Update element success!\n";
    arr_of_int.Output();
    std::cout << '\n';

    int value_1 = 0, value_2 = 4;
    int f_index = arr_of_int.Find(value_1);
    if (f_index == -1)
        std::cout << "Not found element equal to " << value_1 << '\n';
    else
        std::cout << "Element: " << value_1 << ", index: " << f_index << '\n';

    f_index = arr_of_int.Find(value_2);
    if (f_index == -1)
        std::cout << "Not found element equal to " << value_2 << '\n';
    else
        std::cout << "Element: " << value_2 << ", index: " << f_index << "\n\n";

    arr_of_int.Sort(Descending);
    std::cout << "Sort success!\n";
    arr_of_int.Output();

    return 0;
}
