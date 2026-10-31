// Copyright 2026 nghia07-exe.

#ifndef T5_6_EX5_2_EX5_2_H_
#define T5_6_EX5_2_EX5_2_H_

#include <cstdint>
#include <string>

class Client {
   private:
    std::string name_;
    std::string id_;

   public:
    Client(std::string name, std::string id) : name_(name), id_(id) {}
    void Display();
};

class Account {
   protected:
    Client client_;
    std::string account_number_;
    int64_t balance_;

   public:
    Account(Client client, std::string account_number, int64_t balance)
        : client_(client), account_number_(account_number), balance_(balance) {}

    int64_t GetBalance();
    void Deposit(int64_t amount);
    void Withdraw(int64_t amount);
    void Display();
};

class SavingAccount : public Account {
   private:
    float interest_rate_;

   public:
    SavingAccount(Client client, std::string account_number, int64_t balance,
                  float interest_rate)
        : Account(client, account_number, balance),
          interest_rate_(interest_rate) {}
    void ApplyInterest();
    void Display();
};

#endif  // T5_6_EX5_2_EX5_2_H_
