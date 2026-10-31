#include "Ex6_1.h"

#include <iostream>

Array::Array() : data_(nullptr), size_(0) {}
Array::Array(int* data, int size) : size_(size) {
    if (size_ > 0 && data != nullptr) {
        data_ = new int[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = data[i];
        }
    } else {
        data_ = nullptr;
        size_ = 0;
    }
}

Array::Array(const Array& other) {
    size_ = other.size_;
    data_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

void Array::Display() {
    std::cout << "Array:\n  ";
    for (int i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << '\n';
}
void Array::SetAtIndex(int value, int index) {
    if (index >= 0 && index < size_) data_[index] = value;
}
int Array::GetAtIndex(int index) { return data_[index]; }
Array::~Array() {
    delete[] data_;
    size_ = 0;
}

/////////////////////////////////////////////////////////////////////////

void HistogramArray::FindHistSize() {
    int Max = INT_MIN;
    for (int i = 0; i < size_; ++i) {
        if (Max < data_[i]) {
            Max = data_[i];
        }
    }
    hist_size_ = Max + 1;
}
void HistogramArray::ComputeHistogram() {
    FindHistSize();
    delete[] histogram_;
    histogram_ = nullptr;
    if (hist_size_ <= 0) {
        return;
    }
    histogram_ = new int[hist_size_]{0};
    for (int i = 0; i < size_; ++i) {
        histogram_[data_[i]]++;
    }
}
void HistogramArray::Display() {
    std::cout << "Value | Count\n";
    for (int i = 0; i < hist_size_; ++i) {
        if (histogram_[i] > 0) {
            std::cout << i << " | " << histogram_[i] << '\n';
        }
    }
}
void HistogramArray::SetAtIndex(int value, int index) {
    Array::SetAtIndex(value, index);
    ComputeHistogram();
}

HistogramArray::HistogramArray()
    : Array(nullptr, 0), histogram_(nullptr), hist_size_(0) {}

HistogramArray::HistogramArray(const HistogramArray& other) {
    hist_size_ = other.hist_size_;
    histogram_ = new int[hist_size_];
    for (int i = 0; i < hist_size_; ++i) {
        histogram_[i] = other.histogram_[i];
    }
}
HistogramArray::HistogramArray(int* data, int size)
    : Array(data, size), histogram_(nullptr), hist_size_(0) {
    ComputeHistogram();
}

HistogramArray& HistogramArray::operator=(const HistogramArray& other) {
    if (this != &other) {
        Array::operator=(other);

        delete[] histogram_;
        histogram_ = nullptr;
        hist_size_ = other.hist_size_;

        if (hist_size_ <= 0) return *this;
        histogram_ = new int[hist_size_];
        for (int i = 0; i < hist_size_; ++i) {
            histogram_[i] = other.histogram_[i];
        }
    }
    return *this;
}
HistogramArray::~HistogramArray() {
    delete[] histogram_;
    hist_size_ = 0;
}
