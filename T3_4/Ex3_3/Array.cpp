#include "Array.h"

#include <iostream>

Array::Array() : length_(0) {}

Array::Array(int length) {
    if (length <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new int[length]{0};
    length_ = length;
}

Array::Array(int arr[], int length) {
    length_ = length;
    if (length_ <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new int[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = arr[i];
    }
}

Array::Array(const Array& other) {
    length_ = other.length_;
    if (length_ <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new int[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = other.arr_[i];
    }
}

Array::~Array() {
    if (length_ > 0) delete[] arr_;
    length_ = 0;
}
void Array::print() {
    for (int i = 0; i < length_; ++i) {
        std::cout << arr_[i] << " ";
    }
    std::cout << "\n";
}
