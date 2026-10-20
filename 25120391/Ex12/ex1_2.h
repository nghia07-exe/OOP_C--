#ifndef EX1_2_H_
#define EX1_2_H_

#include <iostream>

using Comparator = bool (*)(int, int);
inline void Sort(int arr[], int n, Comparator p) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (p(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

inline bool Ascending(int a, int b) { return a < b; }
inline bool Descending(int a, int b) { return a > b; }

inline void Print(int arr[], int n) {
    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

#endif  // EX1_2_H_
