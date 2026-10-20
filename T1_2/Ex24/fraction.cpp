#include "fraction.h"

#include <iostream>
#include <numeric>

Fraction::Fraction() {
    numerator_ = 0;
    denominator_ = 1;
}
Fraction::Fraction(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
    while (denominator_ == 0) {
        std::cout << "Zero denominator!\n";
        std::cout << "Input \"num/denom\": ";
        std::cin >> numerator_ >> denominator_;
        std::cout << '\n';
    }
}
void Fraction::Input() {
    std::cout << "Input \"num/denom\": ";
    std::cin >> numerator_ >> denominator_;
    std::cout << '\n';
    while (denominator_ == 0) {
        std::cout << "Zero denominator!\n";
        std::cout << "Input \"num/denom\": ";
        std::cin >> numerator_ >> denominator_;
        std::cout << '\n';
    }
}
void Fraction::Output() {
    std::cout << "Output: " << numerator_ << " / " << denominator_ << '\n';
}
void Fraction::GetNum() {
    std::cout << "Get numerator: " << numerator_ << '\n';
}
void Fraction::SetNum(int numerator) {
    numerator_ = numerator;
    std::cout << "Set success!\n";
}
void Fraction::GetDenom() {
    std::cout << "Get denominator: " << denominator_ << '\n';
}
void Fraction::SetDenom(int denominator) {
    if (denominator == 0) {
        std::cout << "Set failed!\n";
        return;
    }
    denominator_ = denominator;
    std::cout << "Set success!\n";
}
Fraction Fraction::Reduce() {
    Fraction r_fraction;
    int GCD = std::gcd(numerator_, denominator_);
    r_fraction.numerator_ = numerator_ / GCD;
    r_fraction.denominator_ = denominator_ / GCD;
    return r_fraction;
}
Fraction Fraction::Inverse() {
    Fraction inv_fraction;
    if (numerator_ == 0) {
        std::cout << "Cannot process: Return this fraction!\n";
        return *this;
    }
    inv_fraction.numerator_ = denominator_;
    inv_fraction.denominator_ = numerator_;
    return inv_fraction;
}
Fraction Fraction::Add(Fraction fraction) {
    Fraction sum;
    sum.numerator_ =
        numerator_ * fraction.denominator_ + denominator_ * fraction.numerator_;
    sum.denominator_ = denominator_ * fraction.denominator_;
    return sum.Reduce();
}
int Fraction::Compare(Fraction fraction) {
    int left = numerator_ * fraction.denominator_;
    int right = denominator_ * fraction.numerator_;
    if (left == right)
        return 0;
    else if (left < right)
        return -1;
    else
        return 1;
}
