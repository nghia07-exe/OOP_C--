#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

class Student {
   private:
    std::string name_;
    float math_score_, physics_score_, chem_score_;

   public:
    Student();
    Student(std::string name, float math_score, float physics_score,
            float chem_score);
    void Input();
    void Output();
    std::string GetName();
    void SetName(std::string name);
    float GetMath();
    void SetMath(float math_score);
    float GetPhysics();
    void SetPhysics(float physics_score);
    float GetChem();
    void SetChem(float chem_score);
    float CalculateGPA();
    char Grade();
};

#endif  // STUDENT_H_
