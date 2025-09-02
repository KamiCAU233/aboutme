#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class ComplexNumber
{
    private:
        double real;
        double imag;
    public:
        ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}
        ComplexNumber operator+(ComplexNumber other) const;
        ComplexNumber operator-(ComplexNumber other) const;
        ComplexNumber operator*(ComplexNumber other) const;
        ComplexNumber operator/(ComplexNumber other) const;
        friend istream& operator>>(istream& is, ComplexNumber& self);
        friend ostream& operator<<(ostream& os, const ComplexNumber& self);
};

ComplexNumber ComplexNumber::operator+(ComplexNumber other) const
{
    return ComplexNumber(real + other.real, imag + other.imag);
}
ComplexNumber ComplexNumber::operator-(ComplexNumber other) const
{
    return ComplexNumber(real - other.real, imag - other.imag);
}
ComplexNumber ComplexNumber::operator*(ComplexNumber other) const
{
    double new_real = real * other.real - imag * other.imag;
    double new_imag = real * other.imag + imag * other.real;
    return ComplexNumber(new_real, new_imag);
}
ComplexNumber ComplexNumber::operator/(ComplexNumber other) const
{
    double new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
    double new_imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
    return ComplexNumber(new_real, new_imag);
}

istream& operator>>(istream& is, ComplexNumber& cn)
{
    string s;
    if (!(is >> s)) return is; // 读取输入失败

    double real = 0.0, imag = 0.0;
    size_t i_pos = s.find('i');

    if (i_pos == string::npos)
    { // 无虚部
        istringstream iss(s);
        if (!(iss >> real))
        {
            is.setstate(ios::failbit);
            return is;
        }
    }
    else
    { // 处理含虚部的情况
        if (i_pos != s.size() - 1)
        { // i不在末尾则无效
            is.setstate(ios::failbit);
            return is;
        }

        size_t op_pos = s.find_last_of("+-", i_pos);
        string real_str, imag_str;

        if (op_pos == string::npos)
        { // 仅有虚部
            real = 0.0;
            imag_str = s.substr(0, i_pos);
        }
        else
        { // 分割实部和虚部
            real_str = s.substr(0, op_pos);
            imag_str = s.substr(op_pos, i_pos - op_pos);

            // 解析实部
            if (!real_str.empty()) {
                istringstream rss(real_str);
                if (!(rss >> real)) {
                    is.setstate(ios::failbit);
                    return is;
                }
            }
        }

        // 解析虚部
        if (imag_str.empty() || imag_str == "+") imag = 1.0;
        else if (imag_str == "-") imag = -1.0;
        else
        {
            istringstream ims(imag_str);
            if (!(ims >> imag))
            {
                is.setstate(ios::failbit);
                return is;
            }
        }
    }

    cn.real = real;
    cn.imag = imag;
    return is;
}

ostream& operator<<(ostream& os, const ComplexNumber& self)
{
    if (self.imag == 0)
    {
        os << fixed << setprecision(2) << self.real;
        return os;
    }
    os << fixed << setprecision(2) << self.real << ((self.imag >= 0) ? '+' : '-') << fabs(self.imag) << 'i';
    return os;
}


//StudybarCommentBegin
void CN() { //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;
	std::cout<< cn1 + cn2 << std::endl;
	std::cout<< cn1 - cn2 << std::endl;
	std::cout<< cn1 * cn2 << std::endl;
	std::cout<< cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd
