#include "Fraction.h"

#include <iostream>
#include <string>

Fraction::Fraction() : num_(0), denom_(1) { count_++; }

Fraction::Fraction(int num, int denom) : num_(num), denom_(denom) {
    if (denom_ == 0) denom_ = 1;
    count_++;
}

Fraction::Fraction(int value) : num_(value), denom_(1) { count_++; }

Fraction::Fraction(std::string frac) {  // "a/b"
    size_t index_div = frac.size();
    for (size_t i = 0; i < frac.size(); ++i) {
        if (frac[i] == '/') {
            index_div = i;
            break;
        }
    }

    int num = 0;
    bool isNegativeNum = false;
    for (size_t i = 0; i < index_div; ++i) {
        if (frac[i] == '-')
            isNegativeNum = !isNegativeNum;
        else if (frac[i] <= '9' && frac[i] >= '0') {
            num *= 10;
            num += frac[i] - '0';
        }
    }

    int denom = 0;
    bool isNegativeDenom = false;
    for (size_t i = index_div + 1; i < frac.size(); ++i) {
        if (frac[i] == '-')
            isNegativeDenom = !isNegativeDenom;
        else if (frac[i] <= '9' && frac[i] >= '0') {
            denom *= 10;
            denom += frac[i] - '0';
        }
    }

    if (isNegativeNum) num = -num;
    if (isNegativeDenom) denom = -denom;

    this->num_ = num;
    this->denom_ = denom;
    if (denom_ == 0) denom_ = 1;
    count_++;
}

Fraction::Fraction(const Fraction& other) {
    this->num_ = other.num_;      // hoặc other->num_
    this->denom_ = other.denom_;  // hoặc other->denom_
    count_++;
}
Fraction::~Fraction() { count_--; }
void Fraction::print() { std::cout << num_ << "/" << denom_ << "\n"; }
void Fraction::printCount() {
    std::cout << "Fraction hien tai: " << count_ << "\n";
}