// Copyright 2026 nghia07-exe.

#ifndef T5_6_EX6_1_EX6_1_H_
#define T5_6_EX6_1_EX6_1_H_
#include <iostream>
class Array {
   protected:
    int* data_;
    int size_;

   public:
    Array();
    Array(int* data, int size);
    Array(const Array& other);
    Array& operator=(const Array& other);

    void SetAtIndex(int value, int index);
    int GetAtIndex(int index);
    void Display();

    ~Array();
};
class HistogramArray : public Array {
   private:
    int* histogram_;
    int hist_size_;

   public:
    using Array::Display;
    using Array::SetAtIndex;
    void FindHistSize();
    void ComputeHistogram();
    void Display();
    void SetAtIndex(int value, int index);

    HistogramArray();
    HistogramArray(int* data, int size);
    HistogramArray(const HistogramArray& other);
    HistogramArray& operator=(const HistogramArray& other);
    ~HistogramArray();
};

#endif  // T5_6_EX6_1_EX6_1_H_
