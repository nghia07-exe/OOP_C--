#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
class Array {
   private:
    int* arr_;
    int length_;

   public:
    Array();
    Array(int length);
    Array(int* arr, int length);
    Array(const Array& other);
    Array operator+(const Array& other);
    Array& operator=(const Array& other);
    Array& operator+=(const Array& other);
    int& operator[](int index);
    explicit operator int*() const;
    friend std::ostream& operator<<(std::ostream& os, const Array& array);
    friend std::istream& operator>>(std::istream& in, Array& array);

    void printArray();

    ~Array();
};

#endif  // ARRAY_H_