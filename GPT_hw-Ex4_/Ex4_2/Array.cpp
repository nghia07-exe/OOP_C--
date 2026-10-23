#include "Array.h"

#include <iostream>
#include <limits>
#include <stdexcept>

Array::Array(int length) : data_(nullptr), length_(length) {
    if (length < 0) {
        throw std::invalid_argument("Array length must not be negative.");
    }
    if (length_ > 0) {
        data_ = new int[length_]{};
    }
}

Array::Array(const Array& other) : Array(other.length_) {
    for (int i = 0; i < length_; ++i) {
        data_[i] = other.data_[i];
    }
}

Array::~Array() { delete[] data_; }

int Array::size() const { return length_; }

Array Array::operator+(const Array& other) const {
    if (length_ > std::numeric_limits<int>::max() - other.length_) {
        throw std::length_error("Concatenated array is too long.");
    }
    Array result(length_ + other.length_);
    for (int i = 0; i < length_; ++i) {
        result.data_[i] = data_[i];
    }
    for (int i = 0; i < other.length_; ++i) {
        result.data_[length_ + i] = other.data_[i];
    }
    return result;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        // Allocate before releasing old data, so allocation failure is safe.
        int* replacement = other.length_ > 0 ? new int[other.length_] : nullptr;
        for (int i = 0; i < other.length_; ++i) {
            replacement[i] = other.data_[i];
        }
        delete[] data_;
        data_ = replacement;
        length_ = other.length_;
    }
    return *this;
}

Array& Array::operator+=(const Array& other) {
    // The temporary also makes array += array safe.
    *this = *this + other;
    return *this;
}

int& Array::operator[](int index) {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Array index is out of range.");
    }
    return data_[index];
}

const int& Array::operator[](int index) const {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Array index is out of range.");
    }
    return data_[index];
}

Array::operator int*() { return data_; }

Array::operator const int*() const { return data_; }

std::istream& operator>>(std::istream& in, Array& array) {
    // Input format: length followed by that many integers.
    int length;
    if (!(in >> length)) return in;
    if (length < 0) {
        in.setstate(std::ios::failbit);
        return in;
    }
    Array temporary(length);
    for (int i = 0; i < length; ++i) {
        if (!(in >> temporary.data_[i])) return in;
    }
    array = temporary;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Array& array) {
    out << '{';
    for (int i = 0; i < array.length_; ++i) {
        if (i > 0) out << ',';
        out << array.data_[i];
    }
    return out << '}';
}
