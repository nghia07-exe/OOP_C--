#include "Fraction.h"

#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator) {
    Normalize(numerator, denominator);
}

void Fraction::Normalize(long long numerator, long long denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator must not be zero.");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    const long long divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (numerator < std::numeric_limits<int>::min() ||
        numerator > std::numeric_limits<int>::max() ||
        denominator > std::numeric_limits<int>::max()) {
        throw std::overflow_error("Reduced fraction does not fit in int.");
    }
    num_ = static_cast<int>(numerator);
    denom_ = static_cast<int>(denominator);
}

Fraction Fraction::FromParts(long long numerator, long long denominator) {
    Fraction result;
    result.Normalize(numerator, denominator);
    return result;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return FromParts(1LL * num_ * other.denom_ + 1LL * other.num_ * denom_,
                     1LL * denom_ * other.denom_);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return FromParts(1LL * num_ * other.denom_ - 1LL * other.num_ * denom_,
                     1LL * denom_ * other.denom_);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return FromParts(1LL * num_ * other.num_, 1LL * denom_ * other.denom_);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.num_ == 0) {
        throw std::domain_error("Cannot divide by a zero fraction.");
    }
    return FromParts(1LL * num_ * other.denom_, 1LL * denom_ * other.num_);
}

bool Fraction::operator==(const Fraction& other) const {
    return num_ == other.num_ && denom_ == other.denom_;
}

bool Fraction::operator<(const Fraction& other) const {
    return 1LL * num_ * other.denom_ < 1LL * other.num_ * denom_;
}

bool Fraction::operator>(const Fraction& other) const { return other < *this; }

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator++() {
    *this += Fraction(1);
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction old = *this;
    ++(*this);
    return old;
}

Fraction& Fraction::operator--() {
    *this = *this - Fraction(1);
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction old = *this;
    --(*this);
    return old;
}

Fraction::operator float() const {
    return static_cast<float>(num_) / static_cast<float>(denom_);
}

Fraction::operator int() const { return num_ / denom_; }

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    // Input format: numerator denominator (for example, 3 4).
    int numerator, denominator;
    if (in >> numerator >> denominator) {
        try {
            Fraction temporary(numerator, denominator);
            fraction = temporary;
        } catch (const std::invalid_argument&) {
            in.setstate(std::ios::failbit);
        } catch (const std::overflow_error&) {
            in.setstate(std::ios::failbit);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    return out << fraction.num_ << '/' << fraction.denom_;
}
