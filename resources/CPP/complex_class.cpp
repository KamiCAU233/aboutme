#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Cmycomplex
{
    private:
        double real;
        double imag;
    public:
        Cmycomplex(double r = 0, double i = 0)
        {
            real = r;
            imag = i;
        }
        void Set(double r, double i)
        {
            real = r;
            imag = i;
        }
        void Show()
        {
            cout << setiosflags(ios::fixed);
            cout << "(" << setprecision(0) << real << (imag > 0 ? "+" : "") << setprecision(0) << imag <<"i)";
        }

        double GetReal() const
        {
            return real;
        }
        double GetImaginary() const
        {
            return imag;
        }
        Cmycomplex Add(Cmycomplex& adder)
        {
            return Cmycomplex(real + adder.real, imag + adder.imag);
        }
        Cmycomplex operator+(Cmycomplex& adder)
        {
            return Cmycomplex(real + adder.real, imag + adder.imag);
        }
        Cmycomplex operator+(int adder)
        {
            return Cmycomplex(real + adder, imag);
        }
        Cmycomplex operator-(Cmycomplex& other)
        {
            return Cmycomplex(real - other.real, imag - other.imag);
        }
        Cmycomplex operator*(Cmycomplex& other)
        {
            double new_real = real * other.real - imag * other.imag;
            double new_imag = real * other.imag + imag * other.real;
            return Cmycomplex(new_real, new_imag);
        }
        Cmycomplex operator/(Cmycomplex& other)
        {
            double new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            double new_imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            return Cmycomplex(new_real, new_imag);
        }
        bool operator==(Cmycomplex other)
        {
            return (real - other.real == 0) && (imag - other.imag == 0);
        }
        bool operator!=(Cmycomplex other)
        {
            return (real - other.real != 0) || (imag - other.imag != 0);
        }
        Cmycomplex sqrt()
        {
            double new_real = -std::sqrt(real + std::sqrt(real * real + imag * imag) / 2.0);
            double new_imag = -imag / std::sqrt(2 * (real + std::sqrt(real * real + imag * imag)));
            return Cmycomplex(((new_real < 0) ? -new_real : new_real), ((new_real < 0) ? -new_imag : new_imag));
        }

        friend Cmycomplex operator+(int a, const Cmycomplex& b);
        friend istream& operator>>(istream& is, Cmycomplex& x);
        friend ostream& operator<<(ostream& os, const Cmycomplex& x);
};


istream& operator>>(istream& is, Cmycomplex& x)
{
    is >> x.real >> x.imag;
    return is;
}

ostream& operator<<(ostream& os, const Cmycomplex& x)
{
    os << "(" << x.real << ((x.imag > 0) ? "+" : "") << x.imag << "i)";
    return os;
}
Cmycomplex operator+(int a, const Cmycomplex& b)
{
    return Cmycomplex(a + b.real, b.imag);
}
