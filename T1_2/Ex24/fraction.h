#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
   private:
    int numerator_;
    int denominator_;

   public:
    Fraction();
    Fraction(int numerator, int denominator);
    void Input();
    void Output();
    void GetNum();
    void SetNum(int numerator);
    void GetDenom();
    void SetDenom(int denominator);
    Fraction Reduce();
    Fraction Inverse();
    Fraction Add(Fraction fraction);
    int Compare(Fraction fraction);
};

#endif  // FRACTION_H_
