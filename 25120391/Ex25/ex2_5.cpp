#include <iostream>

#include "student.h"

int main() {
    Student first_student;
    first_student.Output();

    first_student.SetName("Nguyen_Van_B");
    first_student.SetMath(5.0);
    first_student.SetPhysics(10.0);
    first_student.SetChem(8.5);
    first_student.Output();

    Student second_student("Tran_Van_A", 8.1, 6.5, 10.0);
    std::cout << "Get Name: " << second_student.GetName() << '\n';
    std::cout << "Get Math Score: " << second_student.GetMath() << '\n';
    std::cout << "Get Physics Score: " << second_student.GetPhysics() << '\n';
    std::cout << "Get Chemistry Score: " << second_student.GetChem() << "\n\n";

    std::cout << "First student: " << first_student.GetName() << "\n";
    std::cout << "    GPA: " << first_student.CalculateGPA() << '\n';
    std::cout << "    Grade: " << first_student.Grade() << "\n\n";
    std::cout << "Second student: " << second_student.GetName() << "\n";
    std::cout << "    GPA: " << second_student.CalculateGPA() << '\n';
    std::cout << "    Grade: " << second_student.Grade() << "\n\n";

    Student third_student;
    third_student.Input();  // name(no spaces,replace with _) score score score
    third_student.Output();
    std::cout << "Third student: " << third_student.GetName() << "\n";
    std::cout << "    GPA: " << third_student.CalculateGPA() << '\n';
    std::cout << "    Grade: " << third_student.Grade() << "\n\n";

    return 0;
}
