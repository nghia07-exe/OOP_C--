#include "Array.h"

int main() {
    Array arr1;  // mảng rỗng
    arr1.print();

    Array arr2(5);  // mảng 5 phần tử 0
    arr2.print();

    int a[] = {1, 2, 3, 4, 5};
    Array arr3(a, 5);  // mảng a[]
    arr3.print();

    Array arr4(arr3);  // copy constructor
    arr4.print();

    return 0;
}