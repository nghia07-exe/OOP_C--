#include "Fraction.h"

#include <iostream>

Fraction Fraction::operator+(const Fraction& frac) {
    Fraction res;  // res = new Fraction;
    res.num_ = num_ * frac.denom_ + denom_ * frac.num_;
    res.denom_ = denom_ * frac.denom_;
    return res;
}

Fraction Fraction::operator-(const Fraction& frac) {
    Fraction res;
    res.num_ = num_ * frac.denom_ - denom_ * frac.num_;
    res.denom_ = denom_ * frac.denom_;
    return res;
}

Fraction Fraction::operator*(const Fraction& frac) {
    Fraction res;
    res.num_ = num_ * frac.num_;
    res.denom_ = denom_ * frac.denom_;
    return res;
}
Fraction Fraction::operator/(const Fraction& frac) {
    if (frac.num_ == 0) return Fraction();
    Fraction res;
    res.num_ = num_ * frac.denom_;
    res.denom_ = denom_ * frac.num_;
    return res;
}
// // TO DO: operator * : num_ * f.num_, den * f.den
// // TO DO: operator / : *this * (den/num), num != 0
// // Q: default của "=" là gì trong class
// // Q: khi nào "kdl var", khi nào "const kdl& var"

// --- Toán tử so sánh ---
bool Fraction::operator==(const Fraction& frac) {
    // // TO DO: viết trước operator < và >
    // // Thay thế dòng đầu if (... == 0)
    if (num_ * frac.denom_ - denom_ * frac.num_ == 0) return true;
    return false;
}

bool Fraction::operator!=(const Fraction& frac) { return !(*this == frac); }

bool Fraction::operator>(const Fraction& frac) {
    bool res = false;
    if (*this == frac) return false;
    if (num_ * frac.denom_ - denom_ * frac.num_ > 0) res = !res;
    if (denom_ * frac.denom_ < 0) res = !res;
    return res;
}

bool Fraction::operator<(const Fraction& frac) {
    return !(*this > frac || *this == frac);
}

bool Fraction::operator>=(const Fraction& frac) {
    return (*this > frac || *this == frac);
}

bool Fraction::operator<=(const Fraction& frac) {
    return (*this < frac || *this == frac);
}
// // TO DO: operator >=, <= : use ">", "=", "<"
// // Operator != : use "NOT =="

// // Q: các toán tử =, +=, *= có cần quan tâm tới tham chiếu/tham trị
// không, bộ nhớ (OOP)
// // vd: f1 = f2 + f3 <- "f_temp = f2 + f3" (operator)

// --- Toán tử gán ---
Fraction& Fraction::operator=(const Fraction& frac) {
    num_ = frac.num_;
    denom_ = frac.denom_;
    return *this;
}
Fraction& Fraction::operator+=(const Fraction& frac) {
    num_ = num_ * frac.denom_ + denom_ * frac.num_;
    denom_ = denom_ * frac.denom_;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac) {
    num_ *= frac.num_;
    denom_ *= frac.denom_;
    return *this;
}
/*
*Q: bài làm trên chỉ hoạt động "tĩnh", nếu tạo đối tượng bằng new thì hoạt
động được chưa: bổ sung thêm Constructors, Destructor
*Q: "Fraction operator=..." có hoạt động trong đoạn dưới không:
Fraction* f = new Fraction[10];
    // ... khởi tạo, thêm giá trị
    f[1] = f[2] + f[3]; // code "=", "+" như trên
    -> Có chạy được không?
*/

// // TO DO: trả lời câu hỏi xong thì tiếp tục thiết kế *=, += (Note thêm
// bên dưới)

// --- Toán tử tăng / giảm tiền tố & hậu tố ---
Fraction& Fraction::operator++() {
    num_ += denom_;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    num_ += denom_;
    return temp;
}

Fraction& Fraction::operator--() {
    num_ -= denom_;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    num_ -= denom_;
    return temp;
}

// // ^ : Q: tại sao có Fraction& với pre-i và Fraction với post-i (++)
// // TO DO: operator-- : similar to the previous operator

// --- Ép kiểu ---
Fraction::operator int() const { return num_ / denom_; }

Fraction::operator float() const { return 1.0 * num_ / denom_; }

// --- Toán tử nhập / xuất Stream ---
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.num_ << "/" << frac.denom_;
    return os;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    in >> frac.num_ >> frac.denom_;
    return in;
}

/*
// Q: Một class đầy đủ cần có gì:
// - Xử lý khởi tạo / huỷ hàm: nên có mỗi class
// - Logic khi viết code xử lý khi huỷ hàm, liên quan tới dữ liệu động...
*/