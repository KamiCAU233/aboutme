#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
using namespace std;

class TeamWorkBigInt {
private:
    static const int digits = 10000;
    short integer[digits];
public:
    int sign = 1;

    TeamWorkBigInt(long = 0); // 构造

    friend TeamWorkBigInt operator+(const TeamWorkBigInt&, const TeamWorkBigInt&); // 两个大数相加

    TeamWorkBigInt operator+(int) const; // 大数加int

    TeamWorkBigInt operator-(const TeamWorkBigInt&) const;
    int operator>(const TeamWorkBigInt&) const;
    int operator>=(const TeamWorkBigInt&) const;
    int operator==(const TeamWorkBigInt&) const;
    TeamWorkBigInt operator*(const TeamWorkBigInt&) const;
    TeamWorkBigInt operator*(int) const;
    TeamWorkBigInt operator/(int);
    TeamWorkBigInt operator/(const TeamWorkBigInt&);
    TeamWorkBigInt& operator=(int);
    TeamWorkBigInt& operator+=(const TeamWorkBigInt& a);
    TeamWorkBigInt& operator/=(int);
    friend TeamWorkBigInt pow(TeamWorkBigInt a, int b);
    int getLength() const;
    explicit TeamWorkBigInt(int i);
    friend ostream& operator<<(ostream&, const TeamWorkBigInt&);
};
// end class TeamWorkBigInt

ostream& operator<<(ostream& os, const TeamWorkBigInt& num) {
    // 处理符号位
    if (num.sign == -1) {
        os << '-';
    }

    // 查找最高有效位（非零位）
    int highest = TeamWorkBigInt::digits - 1;
    while (highest >= 0 && num.integer[highest] == 0) {
        highest--;
    }

    // 处理全零的情况
    if (highest < 0) {
        os << 0;
        return os;
    }

    // 按高位到低位顺序输出数字（去除前导零）
    for (int i = highest; i >= 0; i--) {
        os << num.integer[i];
    }

    return os;
}

TeamWorkBigInt::TeamWorkBigInt(long value) {
    for (short& i : integer)
        i = 0;
    int i = 0;
    while (value != 0) {
        integer[i] = value % 10;
        value /= 10;
        i++;
    }
}


TeamWorkBigInt operator+(const TeamWorkBigInt& op2, const TeamWorkBigInt& op3) {
    if (op2.sign == -1 && op3.sign == -1 || op2.sign == 1 && op3.sign == 1) {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++) {
            temp.integer[i] = op2.integer[i] + op3.integer[i] + carry;
            if (temp.integer[i] > 9) {
                temp.integer[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        return temp;
    } else if (op2 > op3) {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++) {
            temp.integer[i] = op2.integer[i] - op3.integer[i] - carry;
            if (temp.integer[i] < 0) {
                temp.integer[i] += 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        temp.sign = op2.sign;
        return temp;
    } else {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++) {
            temp.integer[i] = op3.integer[i] - op2.integer[i] - carry;
            if (temp.integer[i] < 0) {
                temp.integer[i] += 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        temp.sign = op3.sign;
        return temp;
    }
}


int TeamWorkBigInt::getLength() const {
    // 从最高位开始查找第一个非零位
    int highest = digits - 1;
    while (highest >= 0 && integer[highest] == 0) {
        highest--;
    }

    // 处理全零的情况（返回1位）
    if (highest == -1) {
        return 1;
    }

    // 有效位数为最高位索引 + 1（索引从0开始）
    return highest + 1;
}

TeamWorkBigInt TeamWorkBigInt::operator+(int op2) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i < digits; i++) {
        temp.integer[i] = integer[i] + op2 % 10 + carry;
        op2 /= 10;
        if (temp.integer[i] > 9) {
            temp.integer[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return temp;
}

TeamWorkBigInt TeamWorkBigInt::operator-(const TeamWorkBigInt& op2) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i < digits; i++) {
        temp.integer[i] = integer[i] - op2.integer[i] - carry;
        if (temp.integer[i] < 0) {
            temp.integer[i] += 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return temp;
}

int TeamWorkBigInt::operator>(const TeamWorkBigInt& op2) const {
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 0;
    else if (integer[i] > op2.integer[i])
        return 1;
    else
        return 0;
}

int TeamWorkBigInt::operator>=(const TeamWorkBigInt& op2) const {
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 1;
    else if (integer[i] > op2.integer[i])
        return 1;
    else
        return 0;
}

int TeamWorkBigInt::operator==(const TeamWorkBigInt& op2) const {
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 1;
    else
        return 0;
}

TeamWorkBigInt TeamWorkBigInt::operator*(const TeamWorkBigInt& op2) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i <= this->getLength(); i++) {
        for (int j = 0; j <= op2.getLength(); j++) {
            if (i + j < digits) {
                temp.integer[i + j] += integer[i] * op2.integer[j] + carry;
                carry = temp.integer[i + j] / 10;
                temp.integer[i + j] %= 10;
            }
        }
    }
    return temp;
}

TeamWorkBigInt TeamWorkBigInt::operator/(int op2) {
    TeamWorkBigInt temp = *this;
    if (op2 < 0) {
        op2 = -op2;
        temp.sign = temp.sign * -1;
    }
    int temptemp;
    int carry = 0;
    for (int i = getLength() - 1; i >= 0; i--) {
        temptemp = temp.integer[i] + carry * 10;
        temp.integer[i] = temptemp / op2;
        carry = temptemp % op2;
    }
    return temp;
}

TeamWorkBigInt& TeamWorkBigInt::operator=(const int b) {
    for (short& j : integer) {
        j = 0;
    }
    int a = b;
    int k = 0;
    while (a != 0) {
        integer[k] = a % 10;
        a /= 10;
        k++;
    }
    return *this;
}

TeamWorkBigInt::TeamWorkBigInt(int i) {
    for (short& j : integer) {
        j = 0;
    }
    int k = 0;
    while (i != 0) {
        integer[k] = i % 10;
        i /= 10;
        k++;
    }
}

TeamWorkBigInt& TeamWorkBigInt::operator+=(const TeamWorkBigInt& a) {
    if (a.sign == -1) {
        TeamWorkBigInt b = a;
        b.sign = 1;
        *this = *this - b;
        return *this;
    }
    int carry = 0;
    for (int i = 0; i < digits; i++) {
        integer[i] += a.integer[i] + carry;
        if (integer[i] >= 10) {
            integer[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return *this;
}

TeamWorkBigInt& TeamWorkBigInt::operator/=(const int b) {
    int carry = 0;
    int a = -b;
    int temp;
    for (int i = getLength() - 1; i >= 0; i--) {
        temp = integer[i];
        integer[i] = (integer[i] + carry * 10) / a;
        carry = (temp + carry * 10) % a;
    }
    sign *= -1;
    return *this;
}

TeamWorkBigInt TeamWorkBigInt::operator/(const TeamWorkBigInt& a) {
    TeamWorkBigInt temp = *this;
    int num = a.getLength() - 1;
    for (int i = 0; i < getLength(); i++) {
        temp.integer[i] = integer[i + num];
    }
    for (int i = getLength(); i < digits; i++)
        temp.integer[i] = 0;
    return temp;
}

TeamWorkBigInt pow(TeamWorkBigInt a, int b) {
    TeamWorkBigInt temp;
    temp.integer[b] = 1;
    return temp;
}

TeamWorkBigInt TeamWorkBigInt::operator*(int a) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i <= this->getLength(); i++) {
        temp.integer[i] += integer[i] * a + carry;
        carry = temp.integer[i] / 10;
        temp.integer[i] %= 10;
    }
    return temp;
}


//StudybarCommentBegin
int main()
{	int i,N;
    TeamWorkBigInt  n=10,b,x1,x2,s,t,pi;
    cin>>N;
	N--;
	b=pow(n,N+10);

	x1=b*4/5;
	x2=b/-239;
	s=x1+x2;

	for(i=3;i<=N*2;i+=2)
	{	x1/=-25;
		x2/=-57121;
		t=(x1+x2)/i;
		s+=t;
	}
	pi=s*4;
	cout<< (pi/pow(n,10))<<endl;
    return 0;
}
//StudybarCommentEnd
