#ifndef ARRAY_OF_INT_H_
#define ARRAY_OF_INT_H_
class Array {
   private:
    int* arr_;
    int size_;

   public:
    Array();
    void Input();
    void Output();
    int GetSize();
    void SetSize(int sz_arr);
    int GetElement(int index);
    void SetElement(int value, int index);
    int Find(int value);
    void Sort(bool (*p)(int, int));
    void Sort();
};
bool Ascending(int a, int b);
bool Descending(int a, int b);
#endif  // ARRAY_OF_INT_H_
