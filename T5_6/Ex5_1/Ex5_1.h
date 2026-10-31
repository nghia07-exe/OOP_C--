// Copyright 2026 nghia07-exe.

#ifndef T5_6_EX5_1_EX5_1_H_
#define T5_6_EX5_1_EX5_1_H_
#include <string>
class Address {
   private:
    std::string street_;
    std::string city_;
    std::string state_;

   public:
    Address(std::string street, std::string city, std::string state)
        : street_(street), city_(city), state_(state) {}
    void Display();
};

class Student {
   protected:
    std::string name_;
    std::string id_;
    float gpa_;
    Address address_;

   public:
    Student(std::string name, std::string id, float gpa, Address address)
        : name_(name), id_(id), gpa_(gpa), address_(address) {}
    char GetGrade();
    void Display();
};

class ExchangeStudent : public Student {
   private:
    std::string home_country_;
    int exchange_duration_;

   public:
    ExchangeStudent(std::string name, std::string id, float gpa,
                    Address address, std::string home_country,
                    int exchange_duration)
        : Student(name, id, gpa, address),
          home_country_(home_country),
          exchange_duration_(exchange_duration) {}
    void UpdateDuration(int duration);
    void Display();
};
#endif  // T5_6_EX5_1_EX5_1_H_
