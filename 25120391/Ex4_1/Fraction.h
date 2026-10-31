#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class Fraction {
   private:
    int num_;
    int denom_;

   public:
    Fraction() : num_(0), denom_(1) {}
    Fraction(int num, int denom) : num_(num), denom_(denom) {}

    Fraction operator+(const Fraction& frac);
    Fraction operator-(const Fraction& frac);
    Fraction operator*(const Fraction& frac);
    Fraction operator/(const Fraction& frac);

    bool operator==(const Fraction& frac);
    bool operator!=(const Fraction& frac);
    bool operator>(const Fraction& frac);
    bool operator<(const Fraction& frac);
    bool operator<=(const Fraction& frac);
    bool operator>=(const Fraction& frac);

    Fraction& operator=(const Fraction& frac);
    Fraction& operator+=(const Fraction& frac);
    Fraction& operator*=(const Fraction& frac);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    explicit operator int() const;
    explicit operator float() const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
};

#endif