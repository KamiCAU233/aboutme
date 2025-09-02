#include <iostream>
using namespace std;

class Base
{
    public:
    virtual ~Base(){
        cout << "delete Base class" << endl;
    } //完善析构函数的声明，并且尝试一下对析构函数加virtual与不加virtual，看看他们的区别
};

class Derived : public Base
{
    public:
        Derived() {
            p = new int[100];
        }
        ~Derived() {
            cout << "delete new p" << endl;
            cout << "delete Derived class" << endl;
            delete[] p;
        } //完善该析构函数并观察加virtual与不加virtual的区别


    private:
        int *p;
};

//StudybarCommentBegin
void fun(Base *b)
{
	delete b;
}

int main()
{
	Base *B=new Derived();
	fun(B);
	return 0;
}
//StudybarCommentEnd
