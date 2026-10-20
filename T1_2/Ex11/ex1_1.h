#ifndef EX1_1_H_
#define EX1_1_H_

#include <iostream>

template <typename T>
void Sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void Print(const T arr[], int n) {
    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

#endif  // EX1_1_H_
