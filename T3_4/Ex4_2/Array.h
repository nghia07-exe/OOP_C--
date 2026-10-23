#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
   private:
    int* arr_;
    int length_;

   public:
    Array() : length_(0) {}
    Array(int length) : length_(length) {
        arr_ = new int[length_];
        for (int i = 0; i < length_; ++i) arr_[i] = i + 1;
    }
    Array(const Array& other);
    Array operator+(const Array& other);
    Array& operator=(const Array& other);
    Array& operator+=(const Array& other);
    Array& operator[](int index);
    void printArray(const Array& arr, int length);

    ~Array();
}

#endif  // ARRAY_H_