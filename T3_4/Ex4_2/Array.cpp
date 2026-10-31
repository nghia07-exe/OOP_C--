#include "Array.h"

#include <iostream>
Array::Array() : length_(0) {}

Array::Array(int length) {
    length_ = (length);
    arr_ = new int[length_];
    for (int i = 0; i < length_; ++i) arr_[i] = i + 1;
}

Array::Array(int* arr, int length) : arr_(arr), length_(length) {}

Array::Array(const Array& other) {
    length_ = other.length_;
    arr_ = new int[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = other.arr_[i];
    }
}

Array Array::operator+(const Array& other) {
    Array temp;
    temp.length_ = length_ + other.length_;
    temp.arr_ = new int[temp.length_];
    for (int i = 0; i < length_; ++i) {
        temp.arr_[i] = arr_[i];
    }
    for (int i = 0; i < other.length_; ++i) {
        temp.arr_[i + length_] = other.arr_[i];
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
int& Array::operator[](int index) { return arr_[index]; }

Array::operator int*() const {
    return arr_;
}

std::ostream& operator<<(std::ostream& os, const Array& array) {
    for(int i = 0; i < array.length_; ++i) {
        os << array.arr_[i] << ' ';
    }
    os << " Len=" << array.length_;
    return os;
}
std::istream& operator>>(std::istream& in, Array& array) {
    in >> array.length_;
    array.arr_ = new int[array.length_];
    for(int i = 0; i < array.length_; ++i) {
        in >> array.arr_[i];
    }
    return in;
}

void Array::printArray() {
    for (int i = 0; i < length_; ++i) {
        std::cout << arr_[i] << " ";
    }
}

Array::~Array() {
    delete[] arr_;
    length_ = 0;
}
