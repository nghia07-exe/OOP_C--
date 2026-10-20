#include "array_of_int.h"

#include <iostream>
#include <utility>
Array::Array() {
    size_ = 6;
    arr_ = new int[size_]{3, 5, 1, 2, 4, 9};
}
void Array::Input() {
    std::cin >> size_;
    arr_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
        std::cin >> arr_[i];
    }
}
void Array::Output() {
    std::cout << "Array: ";
    for (int i = 0; i < size_; ++i) {
        std::cout << arr_[i] << ' ';
    }
    std::cout << '\n';
}
int Array::GetSize() { return size_; }
void Array::SetSize(int sz_arr) {
    if (sz_arr < 0) size_ = 0;
    size_ = sz_arr;
}
int Array::GetElement(int index) {
    if (index > 0 && index < size_)
        return arr_[index];
    else
        return 0;
}
void Array::SetElement(int value, int index) {
    if (index > 0 && index < size_) arr_[index] = value;
}
int Array::Find(int value) {
    int index = -1;
    for (int i = 0; i < size_; ++i) {
        if (arr_[i] == value) {
            index = i;
            break;
        }
    }
    return index;
}
bool Ascending(int a, int b) { return a < b; }
bool Descending(int a, int b) { return a > b; }
void Array::Sort(bool (*p)(int, int)) {
    for (int i = 0; i < size_ - 1; ++i) {
        for (int j = 0; j < size_ - i - 1; ++j) {
            if (p(arr_[j + 1], arr_[j])) {
                std::swap(arr_[j], arr_[j + 1]);
            }
        }
    }
}
void Array::Sort() { Sort(Ascending); }
