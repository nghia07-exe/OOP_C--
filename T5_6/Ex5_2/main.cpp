// Copyright 2026 nghia07-exe.

#include <iostream>

#include "Ex5_2.h"

int main() {
    Client client_test("Cao Huu Nghia", "25120391");
    Client richest_client("Pham Nhat Vuong", "VinGroup");

    std::cout << "Client info:\n";
    client_test.Display();
    std::cout << '\n';
    ////
    Account my_account(client_test, "0839610807", 200000);
    Account vip_account(richest_client, "0123456789", 922500000000000);

    int64_t m1 = 100000000;
    vip_account.Deposit(m1);
    std::cout << "His balance: " << vip_account.GetBalance()
              << " after deposit " << m1 << '\n';
    int64_t m2 = 70000;
    my_account.Withdraw(m2);
    std::cout << "My balance: " << my_account.GetBalance() << " after withdraw "
              << m2 << '\n';

    std::cout << "Account info:\n";
    vip_account.Display();
    std::cout << '\n';

    ////
    SavingAccount my_saving_account(client_test, "0839610807", 200000, 0.1234);
    SavingAccount another_saving_account(richest_client, "0123456789",
                                         922500000000000, 0.2677);

    my_saving_account.ApplyInterest();
    another_saving_account.ApplyInterest();

    std::cout << "Saving account info:\n";
    my_saving_account.Display();
    std::cout << '\n';

    std::cout << "Saving account info:\n";
    another_saving_account.Display();

    return 0;
}
