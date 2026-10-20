#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <string>

template <typename T>
class Array {
   private:
    T* arr_;
    int length_;

   public:
    Array();
    Array(int length);
    Array(T arr[], int length);
    Array(const Array& other);
    ~Array();
    void print();
};

template <typename T>
Array<T>::Array() : length_(0) {}

template <typename T>
Array<T>::Array(int length) {
    if (length <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new T[length]{};
    length_ = length;
}

template <typename T>
Array<T>::Array(T arr[], int length) {
    length_ = length;
    if (length_ <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new T[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = arr[i];
    }
}

template <typename T>
Array<T>::Array(const Array& other) {
    length_ = other.length_;
    if (length_ <= 0) {
        length_ = 0;
        return;
    }
    arr_ = new T[length_];
    for (int i = 0; i < length_; ++i) {
        arr_[i] = other.arr_[i];
    }
}

template <typename T>
Array<T>::~Array() {
    if (length_ > 0) delete[] arr_;
    length_ = 0;
}

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < length_; ++i) {
        std::cout << arr_[i] << " ";
    }
    std::cout << "\n";
}

/*
3.4 Đổi int thành T (Ex 3.3)
    Dòng trên class: template<typename T>
    * Lưu ý "inline", tách khai báo / định nghĩa hàm
      ^ tại sao phải
      còn tách file thì sao?
*/

#endif  // ARRAY_H_