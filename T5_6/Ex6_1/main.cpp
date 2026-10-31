// Copyright 2026 nghia07-exe.

#include <iostream>

#include "Ex6_1.h"

int main() {
    // Hàm main được hỗ trợ bởi AI duy nhất hỗ trợ test đơn giản các Class
    std::cout << "================ TEST CLASS ARRAY ================\n";
    {
        int raw_data[] = {1, 2, 3, 4, 5};
        Array arr1(raw_data, 5);

        std::cout << "arr1 elements: ";
        arr1.Display();

        std::cout << "arr1[2] = " << arr1.GetAtIndex(2) << "\n";

        std::cout << "Setting arr1 index 2 to 99...\n";
        arr1.SetAtIndex(99, 2);
        std::cout << "arr1 after set: ";
        arr1.Display();

        std::cout << "Testing Array Copy Constructor:\n";
        Array arr2 = arr1;
        std::cout << "arr2 elements: ";
        arr2.Display();

        std::cout << "Testing Array Assignment Operator:\n";
        Array arr3;
        arr3 = arr1;
        std::cout << "arr3 elements: ";
        arr3.Display();
    }
    std::cout << "Array destruction test passed (no crash).\n\n";

    std::cout << "============ TEST CLASS HISTOGRAMARRAY ============\n";
    {
        std::cout << "--- 1. Parameterized Constructor & Initial State ---\n";
        int sample[] = {2, 0, 1, 2, 0, 3, 2};
        HistogramArray hist_arr1(sample, 7);

        std::cout << "hist_arr1 elements and histogram:\n";
        hist_arr1.Display();

        std::cout << "\n--- 2. Test Auto-Recompute on SetAtIndex ---\n";
        std::cout << "Updating index 0 from 2 to 3...\n";
        hist_arr1.SetAtIndex(3, 0);
        hist_arr1.Display();

        std::cout << "Updating index 1 from 0 to 1...\n";
        hist_arr1.SetAtIndex(1, 1);
        hist_arr1.Display();

        std::cout << "\n--- 3. Test Copy Constructor (Deep Copy) ---\n";
        HistogramArray hist_arr2 = hist_arr1;
        std::cout << "hist_arr2 (copied from hist_arr1):\n";
        hist_arr2.Display();

        std::cout << "Modifying hist_arr2 index 0 to verify deep copy...\n";
        hist_arr2.SetAtIndex(0, 0);
        std::cout << "hist_arr2 after edit:\n";
        hist_arr2.Display();
        std::cout << "hist_arr1 should remain unchanged:\n";
        hist_arr1.Display();

        std::cout
            << "\n--- 4. Test Assignment Operator & Self-Assignment ---\n";
        HistogramArray hist_arr3;
        hist_arr3 = hist_arr1;
        std::cout << "hist_arr3 after assignment:\n";
        hist_arr3.Display();

        std::cout << "Testing self-assignment (hist_arr3 = hist_arr3)...\n";
        hist_arr3 = hist_arr3;
        std::cout << "hist_arr3 after self-assignment:\n";
        hist_arr3.Display();
    }
    std::cout << "HistogramArray destruction test passed (no crash).\n";

    return 0;
}
