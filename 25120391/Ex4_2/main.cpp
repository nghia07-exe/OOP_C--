#include <iostream>
#include <sstream>
#include "Array.h"

using namespace std;

int main() {
    cout << "=== 1. TEST INPUT / OUTPUT ===" << '\n';
    stringstream ss("3 1 0 7");
    Array arr_inp;
    ss >> arr_inp;
    cout << "arr_inp (nhap tu stream): " << arr_inp << '\n';
    
    int* int_arr = new int[2]{4, 5};
    Array arr1(int_arr, 2);
    Array arr2(3);
    
    cout << "arr1: " << arr1 << '\n';
    cout << "arr2: " << arr2 << '\n';


    cout << "\n=== 2. TEST (+, =, +=) ===" << '\n';

    Array arr3(arr1 + arr2);  // arr3 = arr1 + arr2
    Array arr4 = arr2 + arr1;

    cout << "arr3 (copy structor:arr1 + arr2): " << arr3 << '\n';

    cout << "arr4 = arr2 + arr1 = "<< arr4 << '\n';

    arr2 += arr2;
    cout << "arr2 += arr2: arr2 = "<< arr2 << '\n';



    cout << "\n=== 3. TEST ([], type-cast:int*) ===" << '\n';

    cout << "arr2[4] va arr3[1]: " << arr2[4] << " " << arr3[1];
    cout << '\n';

    int* int_arr_zero = (int*)arr_inp;
    int_arr_zero[0] = int_arr_zero[1] = int_arr_zero[2] = 0;
    cout << "arr_inp <- int* int_arr_zero: "<< arr_inp << '\n';


    return 0;
}