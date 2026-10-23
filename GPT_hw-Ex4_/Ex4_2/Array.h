#ifndef GPT_EX4_2_ARRAY_H_
#define GPT_EX4_2_ARRAY_H_

#include <iosfwd>

class Array {
   private:
    int* data_;
    int length_;

   public:
    explicit Array(int length = 0);
    Array(const Array& other);
    ~Array();

    int size() const;
    Array operator+(const Array& other) const;
    Array& operator=(const Array& other);
    Array& operator+=(const Array& other);

    int& operator[](int index);
    const int& operator[](int index) const;
    explicit operator int*();
    explicit operator const int*() const;

    friend std::istream& operator>>(std::istream& in, Array& array);
    friend std::ostream& operator<<(std::ostream& out, const Array& array);
};

#endif  // GPT_EX4_2_ARRAY_H_
