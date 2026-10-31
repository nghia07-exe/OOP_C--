// Copyright 2026 nghia07-exe.

#include <iostream>

#include "Ex5_1.h"

using namespace std;

int main() {
    Address addr("227 Nguyen Van Cu", "Ho Chi Minh City", "Vietnam");

    Student s("Nghia", "25120391", 8.49f, addr);

    ExchangeStudent ex("Daniel", "25120001", 7.8f, addr, "USA", 6);

    cout << "===== Address =====\n";
    addr.Display();

    cout << "\n\n===== Student =====\n";
    s.Display();
    cout << "\nGrade: " << s.GetGrade() << endl;

    cout << "\n\n===== Exchange Student =====\n";
    ex.Display();

    cout << "\n\n===== Update Duration =====\n";
    ex.UpdateDuration(12);
    ex.Display();

    return 0;
}
