#include <iostream>
using namespace std;

class Person
{
public:
    virtual void name(){ cout<<"A::name"<<endl;}
private:
    virtual void sex(){cout<<"A::sex"<<endl;}
};

class Student : public Person
{
public:
    virtual void name(){cout<<"B::name"<<endl;}
    virtual void address(){cout<<"B::address"<<endl;}
private:
    virtual void ID(){cout<<"B::ID"<<endl;}
};

typedef void (*Fun)(void);//定义一个函数指针
// 函数指针定义：typedef 返回值类型 (*指针变量名)(参数类型列表);

int main()
{
    Person person;
    cout<<"\nGet Vptr in the Person"<<endl;

    for(int i = 0; i < 2; i++)
    {
        // 1. (int*)(&person)     - 获取对象地址并转换为int*指针
        // 2. *(int*)(&person)    - 解引用获取虚函数表指针(vptr)
        // 3. (int*) * (int*)(&person) - 将vptr转换为int*指针
        // 4. ((int*) * (int*)(&person) + i) - 偏移到第i个虚函数地址
        // 5. * ((int*) * (int*)(&person) + i) - 解引用获取函数地址
        // 6. (Fun) * (...) - 将函数地址转换为Fun类型的函数指针
        Fun p = (Fun) * ((int*)*(int*)(&person) + i);
        p();
    }
    cout<<"\nGet Vptr in the Student"<<endl;

    Student stu;
    for (int i = 0; i < 4; i++)
    {
        Fun p = (Fun) * ((int*) * (int*)(&stu) + i);
        p();
    }
}
