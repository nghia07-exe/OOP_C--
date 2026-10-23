#include "Array.h"

#include <iostream>

Array::Array(const Array& other) {
    length_ = other.length_;
    arr_ = new int[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = other.arr_[i];
    }
}

Array Array::operator+(const Array& other) {
    Array* temp;
    temp->length_ = length_ + other.length_;
    temp->arr_ = new int[temp->length];
    for (int i = 0; i < length_; ++i) {
        temp->arr_[i] = arr_[i];
    }
    for (int i = 0; i < other.length_; ++i) {
        temp->arr_[i + length_] = other.arr_[i];
    }
    return temp;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete arr_;
        length_ = other.length_;
        arr_ = new int[length_];
        for (int i = 0; i < length_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }
    return *this;
}
Array& Array::operator+=(const Array& other) {
    *this = *this + other;
    return *this;
}
Array& Array::operator[](int index) { return arr_[index]; }

void Array::printArray(const Array& arr, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
}

Array::~Array() {
    delete[] arr_;
    length_ = 0;
}
