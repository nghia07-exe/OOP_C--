#ifndef FRACTION_H_
#define FRACTION_H_


#include <string>

class Fraction {
   private:
    int num_, denom_;
    static int count_;
   public:
    Fraction();
    Fraction(int num, int denom);
    Fraction(int value);
    Fraction(std::string frac);
    Fraction(const Fraction& other);
    ~Fraction();
    void print();
    static void printCount();
};

#endif  // FRACTION_H_