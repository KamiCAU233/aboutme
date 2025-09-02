#include <iostream>
using namespace std;

// 可怜的编译器怎么也无法推导出 SomeClass h 代表什么
// 必须在声明模板的时候强行声明一个默认的类型


// 多次尝试修改仍无果，必须修改 main 函数了
// 但 main 函数是后缀里的，改不了啊
// 只能修改 SomeClass，缩小 SomeClass 的功能了
class SomeClass {
    public:
        double val1;
        double val2;
        SomeClass() : val1(0), val2(0) {}
        SomeClass(double v1, double v2) : val1(v1), val2(v2) {}
        friend istream& operator>>(istream& is, SomeClass& obj)
        {
            is >> obj.val1 >> obj.val2;
            return is;
        }
        friend ostream& operator<<(ostream& os, const SomeClass obj)
        {
            os << '(' << obj.val1 << ',' << obj.val2 << ')';
            return os;
        }
        bool operator==(SomeClass obj)
        {
            return (val1 == obj.val1) && (val2 == obj.val2);
        }
};


// 可怜的编译器还是推导不出 T1 和 T2 分别代表什么
// 给编译器加一个“推导指引”
// 推导指引是C++17才引入的特性，可怜的学吧版本有些低


template <typename T1, typename T2>
bool isEqualTo(T1 a, T2 b) {
    return (a == b);
}
//StudybarCommentBegin
int main()
{
    int a;   // integers used for
    int b;   // testing equality

    // test if two ints input by user are equal
    // cout << "Enter two integer values: ";
    cin >> a >> b;

    char c;  // chars used for
    char d;  // testing equality

    // test if two chars input by user are equal
    //    cout << "\nEnter two character values: ";
    cin >> c >> d;

    double e;   // double values used for
    double f;   // testing equality

    // test if two doubles input by user are equal
    //    cout << "\nEnter two double values: ";
    cin >> e >> f;

    SomeClass g( 1, 1.1 );  // SomeClass objects used
    SomeClass h;  // for testing equality

    cin >> h;

    cout << a << " and " << b << " are "
    << ( isEqualTo( a, b ) ? "equal" : "not equal" ) << '\n';

    cout << c << " and " << d << " are "
    << ( isEqualTo( c, d ) ? "equal" : "not equal" ) << '\n';


    cout << e << " and " << f << " are "
    << ( isEqualTo( e, f ) ? "equal" : "not equal") << '\n';

    // test if two SomeClass objects are equal
    // uses overloaded << operator
    cout << "The class objects " << g << " and " << h << " are "
    << ( isEqualTo( g, h ) ? "equal" : "not equal" ) << '\n';

    return 0;

} // end main

//StudybarCommentEnd
