#ifndef EX1_3_H_
#define EX1_3_H_

#include <iostream>

template <typename T>
using Comparator = bool (*)(const T&, const T&);
template <typename T>
void Sort(T arr[], int n, Comparator<T> p) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (p(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
bool Ascending(const T& a, const T& b) {
    return a < b;
}
template <typename T>
bool Descending(const T& a, const T& b) {
    return a > b;
}

template <typename T>
void Print(const T arr[], int n) {
    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

#endif  // EX1_3_H_
