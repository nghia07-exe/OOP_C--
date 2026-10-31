#include <iostream>
using namespace std;

class A {
   public:
    int t;
    A(int t_) : t(t_) {}
};

class B : public A {
   public:
    B(A a);
    void t3() { cout << t; }

   private:
    void t1() { cout << t; }

   protected:
    void t2() { cout << t; }
};
B::B(A a) : A(a.t) {}
int main() {
    A a1(5);
    cout << a1.t;

    B b(a1);
    // b.t1();
    // b.t2();
    b.t3();
    return 0;
}
