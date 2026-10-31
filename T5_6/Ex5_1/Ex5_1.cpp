// Copyright 2026 nghia07-exe.

#include "Ex5_1.h"

#include <iostream>
#include <string>

// Implement Address class

void Address::Display() {
    std::cout << "Address info (Current):\n";
    std::cout << "  Street: " << street_ << '\n';
    std::cout << "  City: " << city_ << '\n';
    std::cout << "  State: " << state_ << '\n';
}

// Implement Student class

char Student::GetGrade() {
    if (gpa_ >= 9.0)
        return 'A';
    else if (gpa_ >= 7.0)
        return 'B';
    else if (gpa_ >= 5.0)
        return 'C';
    else
        return 'D';
}

void Student::Display() {
    std::cout << "Student info:\n";
    std::cout << "  Name: " << name_ << '\n';
    std::cout << "  Student ID: " << id_ << '\n';
    std::cout << "  GPA: " << gpa_ << '\n';
    address_.Display();
}

// Implement ExchangeStudent class

void ExchangeStudent::UpdateDuration(int duration) {
    exchange_duration_ = duration;
}

void ExchangeStudent::Display() {
    std::cout << "Exchange student info:\n";
    std::cout << "  Home country: " << home_country_ << '\n';
    std::cout << "  Exchange duration: " << exchange_duration_ << '\n';
    Student::Display();
}
