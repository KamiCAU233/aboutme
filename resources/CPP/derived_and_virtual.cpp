#include <iostream>
using namespace std;
class Base {
    public:
    Base(){ cout << "Base constructor" << endl;}
    ~Base() {cout << "Base destructor" << endl;}
    virtual void f() {cout << "Base::f" << endl;}
    void g()  {cout << "Base::g" << endl;}
    void h()  {cout << "Base::h" << endl;}
};

//StudybarCommentBegin
class Derived : public Base {
    public:
        Derived(){ cout << "Derived constructor" << endl;}
        ~Derived() {cout << "Derived destructor" << endl;}
        virtual void f() {cout << "Derived::f" << endl;}
        virtual void g() const {cout << "Derived::g" << endl;}
        virtual void h() const {cout << "Derived::h" << endl;}
};


 int main() {
     Base *b = new Derived;
     b->f();
     b->g();
     b->h();
     delete b;
     b = NULL;
     return 0;
 }
//StudybarCommentEnd


