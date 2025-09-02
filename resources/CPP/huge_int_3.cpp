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
    HugeInt( const HugeInt& );
    // addition operator; HugeInt + HugeInt
    HugeInt operator+(const HugeInt&) const;
    HugeInt operator-(const HugeInt&) const;

    // addition operator; HugeInt + int
    HugeInt operator+( int ) const;

    // addition operator; HugeInt + string that represents large integer value
    HugeInt operator+( const char * ) const;

    bool operator==(const HugeInt&) const;
    bool operator!=(const HugeInt&) const;
    bool operator>(const HugeInt&) const;
    bool operator<(const HugeInt&) const;
    bool operator<=(const HugeInt&) const;
    bool operator>=(const HugeInt&) const;

    int getLength() const;
private:
    short integer[digits]; // 数据是倒着从个位到最后一位存储的，如果没有则为0；
};


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


HugeInt::HugeInt(const HugeInt& other) {
    for (int i = 0; i < 30; i++) {
        integer[i] = other.integer[i];
    }
}

bool HugeInt::operator==(const HugeInt& other) const {
    if (getLength() != other.getLength()) {
        return false;
    }
    for (int i = 0; i < 30; i++) {
        if (integer[i] != other.integer[i]) {
            return false;
        }
    }
    return true;
}

bool HugeInt::operator!=(const HugeInt& other) const {
    return !(*this == other);
}

bool HugeInt::operator>(const HugeInt& other) const {
    if (getLength() != other.getLength()) {
        return getLength() > other.getLength();
    }
    for (int i = getLength() - 1; i >= 0; i++) {
        if (integer[i] != other.integer[i]) {
            return integer[i] > other.integer[i];
        }
    }
}

bool HugeInt::operator<(const HugeInt& other) const {
    return !(*this >= other);
}

bool HugeInt::operator>=(const HugeInt& other) const {
    return ((*this > other) || (*this == other));
}

bool HugeInt::operator<=(const HugeInt& other) const {
    return ((*this < other) || (*this == other));
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
}

HugeInt HugeInt::operator-(const HugeInt& subtrahend) const {
    int p = 0;
    HugeInt result(p);
    for (int i = 0; i < 30; i++) {
        result.integer[i] += integer[i] - subtrahend.integer[i];
        if (result.integer[i] < 0) {
            result.integer[i + 1] -= 1;
            result.integer[i] += 10;
        }
    }
    return result;
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
    HugeInt n5( "12341234" );
    HugeInt n6( "7888" );
    HugeInt result;

    cout << "n1 is " << n1 << "\nn2 is " << n2
    << "\nn3 is " << n3 << "\nn4 is " << n4
    << "\nn5 is " << n5 << "\nn6 is " << n6
    << "\nresult is " << result << "\n\n";

    // test relational and equality operators
    if ( n1 == n2 )
        cout << "n1 equals n2" << endl;

    if ( n1 != n2 )
        cout << "n1 is not equal to n2" << endl;

    if ( n1 < n2 )
        cout << "n1 is less than n2" << endl;

    if ( n1 <= n2 )
        cout << "n1 is less than or equal to n2" << endl;

    if ( n1 > n2 )
        cout << "n1 is greater than n2" << endl;

    if ( n1 >= n2 )
        cout << "n1 is greater than or equal to n2" << endl;

    result = n1 + n2;
    cout << n1 << " + " << n2 << " = " << result << "\n\n";

    cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";

    result = n1 + 9;
    cout << n1 << " + " << 9 << " = " << result << endl;

    result = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << result << endl;

    result = n5 - n6;
    cout << n5 << " - " << n6 << " = " << result << endl;

    return 0;
} // end main

//StudybarCommentEnd
