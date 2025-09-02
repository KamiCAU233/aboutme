#include <iostream>
using namespace std;

class MyClass
{
    public:
        int value;

        MyClass(int val) : value(val) {}

        int getValue() const
        {
            value = value + 1;
            return value;
        }

        void setValue(int new_value)
        {
            value = new_value;
        }
};


int main()
{
    MyClass obj(15);
    cout << obj.getValue() << endl;
    obj.value = 10;
    cout << obj.getValue() << endl;
    obj.setValue(14);
    cout << obj.getValue() << endl;

}
