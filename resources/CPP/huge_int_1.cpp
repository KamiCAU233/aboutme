//StudybarCommentBegin
#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

class HugeInt
{
    friend ostream &operator<<( ostream &, const HugeInt & );
public:
    static const int digits = 30;
    HugeInt( long = 0 ); // conversion/default constructor
    HugeInt( const char * ); // conversion constructor

    // addition operator; HugeInt + HugeInt
    HugeInt operator+( const HugeInt & ) const;

    // addition operator; HugeInt + int
    HugeInt operator+( int ) const;

    // addition operator; HugeInt + string that represents large integer value
    HugeInt operator+( const char * ) const;

    int getLength() const;
private:
    short integer[digits]; // 数据是倒着从个位到最后一位存储的，如果没有则为0；
};

//StudybarCommentEnd

HugeInt::HugeInt(long num) {
    for (int i = 0; i < 30; i++) {
        integer[i] = 0;
    }
    for (int i = 0; num != 0; i++) {
        integer[i] = num % 10;
        num /= 10;
    }
}

HugeInt::HugeInt(const char* str) {
    for (int i = 0; i < 30; i++) {
        integer[i] = 0;
    }
    for (int i = 0; i < strlen(str); i++) {
        integer[i] = str[strlen(str) - 1 - i] - '0';
    }
}

int HugeInt::getLength() const {
    for (int i = 29; i >= 0; i--) {
        if (integer[i] != 0) {
            return i + 1;
        }
    }
    return 0;
}

HugeInt HugeInt::operator+(const HugeInt& adder) const {
    int p = 0;
    HugeInt result(p);
    for (int i = 0; i < 30; i++) {
        result.integer[i] += integer[i] + adder.integer[i];
        if (result.integer[i] >= 10) {
            result.integer[i + 1] = result.integer[i] / 10;
            result.integer[i] %= 10;
        }
    }
    return result;

//    99999999999999999999999999999
//                              + 1
// = 999999999999999999999999999910

}

HugeInt HugeInt::operator+(int other) const {
    HugeInt adder(other);
    return *this + adder;
}

HugeInt HugeInt::operator+(const char* str) const {
    HugeInt adder(str);
    return *this + adder;
}

ostream& operator<<(ostream& os, const HugeInt& obj) {
    if (obj.getLength() == 0) os << '0';
    for (int i = obj.getLength() - 1; i >= 0; i--) {
        os << obj.integer[i];
    }
    return os;
}

//StudybarCommentBegin
int main()
{
    HugeInt n1( 7654321 );
    HugeInt n2( 7891234 );
    HugeInt n3( "99999999999999999999999999999" );
    HugeInt n4( "1" );
    HugeInt result;

    cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nresult is " << result << "\n\n";


    result = n1 + n2;
    cout << n1 << " + " << n2 << " = " << result << "\n\n";

    cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";

    result = n1 + 9;
    cout << n1 << " + " << 9 << " = " << result << endl;

    result = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << result << endl;
    return 0;
} // end main

//StudybarCommentEnd


//     7654321
//  +  7891234
//  = 15545555



