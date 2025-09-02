//StudybarCommentBegin
#include <iostream>
#include <iomanip>
#include <string>
//StudybarCommentEnd

class ComplexNumber
{
    private:
        double real, imag;
    public:
        ComplexNumber(double a = 0, double b = 0)
        {
            real = a;
            imag = b;
        }
        ComplexNumber operator+ (ComplexNumber& adder)
        {
            return ComplexNumber(real + adder.real, imag + adder.imag);
        }
        ComplexNumber operator- (ComplexNumber& x)
        {
            return ComplexNumber(real - x.real, imag - x.imag);
        }
        ComplexNumber operator* (ComplexNumber &other)
        {
            double new_real = real * other.real - imag * other.imag;
            double new_imag = real * other.imag + imag * other.real;
            return ComplexNumber(new_real, new_imag);
        }
        ComplexNumber operator/(ComplexNumber& other)
        {
            double new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            double new_imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            return ComplexNumber(new_real, new_imag);
        }

        friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& x);
        friend std::istream& operator>>(std::istream& is, ComplexNumber& x);
};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& x)
{
    if (x.imag == 0)
    {
        os << x.real;
        return os;
    }
    os << std::fixed << std::setprecision(2) << x.real << ((x.imag > 0) ? "+" : "") << x.imag << "i";
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber &x)
{
    is >> x.real >> x.imag;
    return is;
}


//StudybarCommentBegin
void CN() { //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;
	std::cout << cn1 + cn2 << std::endl;
	std::cout << cn1 - cn2 << std::endl;
	std::cout << cn1 * cn2 << std::endl;
	std::cout << cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd
