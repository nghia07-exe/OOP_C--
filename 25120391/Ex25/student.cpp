#include "student.h"

#include <iostream>
#include <string>

Student::Student() {
    name_ = "Cao_Huu_Nghia";
    math_score_ = 8.0;
    physics_score_ = 9.0;
    chem_score_ = 6.5;
}
Student::Student(std::string name, float math_score, float physics_score,
                 float chem_score) {
    name_ = name;
    math_score_ = math_score;
    physics_score_ = physics_score;
    chem_score_ = chem_score;
}

void Student::Input() {
    // Format: [name_] [math_score_] [physics_score_] [chem_score_]
    std::cin >> name_;
    std::cin >> math_score_ >> physics_score_ >> chem_score_;
}
void Student::Output() {
    std::cout << "Information:\n";
    std::cout << "    Name: " << name_ << '\n';
    std::cout << "    Math: " << math_score_ << '\n';
    std::cout << "    Physics: " << physics_score_ << '\n';
    std::cout << "    Chemistry: " << chem_score_ << '\n';
    std::cout << '\n';
}
std::string Student::GetName() { return name_; }

void Student::SetName(std::string name) { name_ = name; }

float Student::GetMath() { return math_score_; }

void Student::SetMath(float math_score) { math_score_ = math_score; }
float Student::GetPhysics() { return physics_score_; }
void Student::SetPhysics(float physics_score) {
    physics_score_ = physics_score;
}
float Student::GetChem() { return chem_score_; }
void Student::SetChem(float chem_score) { chem_score_ = chem_score; }
float Student::CalculateGPA() {
    return (math_score_ + physics_score_ + math_score_) / 3;
}
char Student::Grade() {
    float GPA = CalculateGPA();
    if (GPA >= 9.0)
        return 'A';
    else if (GPA >= 7.0)
        return 'B';
    else if (GPA >= 5.0)
        return 'C';
    else
        return 'D';
}
