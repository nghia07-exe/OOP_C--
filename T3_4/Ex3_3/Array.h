#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
   private:
    int* arr_;
    int length_;

   public:
    Array();
    Array(int length);
    Array(int arr[], int length);
    Array(const Array& other);
    ~Array();
    void print();
};

/*
3.4 Đổi int thành T (Ex 3.3)
    Dòng trên class: template<typename T>
    * Lưu ý "inline", tách khai báo / định nghĩa hàm
      ^ tại sao phải
      còn tách file thì sao?
*/

#endif  // ARRAY_H_