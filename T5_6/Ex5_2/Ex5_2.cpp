// Copyright 2026 nghia07-exe.

#include "Ex5_2.h"

#include <cstdint>
#include <iostream>

void Client::Display() {
    std::cout << "  Name: " << name_ << '\n';
    std::cout << "  Client ID: " << id_ << '\n';
}

int64_t Account::GetBalance() { return balance_; }

void Account::Deposit(int64_t amount) { balance_ += amount; }

void Account::Withdraw(int64_t amount) { balance_ -= amount; }

void Account::Display() {
    client_.Display();
    std::cout << "  Account number: " << account_number_ << '\n';
    std::cout << "  Balance: " << balance_ << " VND\n";
}

void SavingAccount::ApplyInterest() { balance_ += balance_ * interest_rate_; }

void SavingAccount::Display() {
    Account::Display();
    std::cout << "  Interest rate: " << interest_rate_ << '\n';
}
