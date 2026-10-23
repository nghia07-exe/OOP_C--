#ifndef GPT_EX4_1_FRACTION_H_
#define GPT_EX4_1_FRACTION_H_

#include <iosfwd>

class Fraction {
   private:
    int num_;
    int denom_;

    // Keep the fraction reduced, with a strictly positive denominator.
    void Normalize(long long numerator, long long denominator);
    static Fraction FromParts(long long numerator, long long denominator);

   public:
    Fraction(int numerator = 0, int denominator = 1);
    Fraction(const Fraction& other) = default;
    ~Fraction() = default;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    Fraction& operator=(const Fraction& other) = default;
    Fraction& operator+=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    explicit operator float() const;
    explicit operator int() const;

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

#endif  // GPT_EX4_1_FRACTION_H_
