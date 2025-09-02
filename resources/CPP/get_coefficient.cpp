#include <iostream>
#include <cmath>
using namespace std;

class Cmycomplex
{
    private:
        double real, imag;
    public:
        Cmycomplex(double r = 0, double i = 0) : real(r), imag(i) {}
        double getx() const {return real;}
        double gety() const {return imag;}
        void Show() const {cout << "(" << real << (imag >= 0 ? "+" : "-") << fabs(imag) << "i" << ")" << endl;}
        void display() const {printf("%lf %lf\n", real, imag);}
        Cmycomplex operator+(const Cmycomplex& other) const {return Cmycomplex(real + other.real, imag + other.imag);}
        Cmycomplex operator-(const Cmycomplex& other) const {return Cmycomplex(real - other.real, imag - other.imag);}
        Cmycomplex operator*(const Cmycomplex& other) const
        {
            double new_real = real * other.real - imag * other.imag;
            double new_imag = real * other.imag + imag * other.real;
            return Cmycomplex(new_real, new_imag);
        }
        Cmycomplex operator/(const Cmycomplex& other) const
        {
            if (other.real == 0 && other.imag == 0)
            {
                cout << "Division by zero!";
            }
            double new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            double new_imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            return Cmycomplex(new_real, new_imag);
        }
        bool operator==(const Cmycomplex other)
        {
            return (real - other.real == 0) && (imag - other.imag == 0);
        }
        bool operator!=(const Cmycomplex other)
        {
            return (real - other.real != 0) || (imag - other.imag != 0);
        }
        friend Cmycomplex operator*(int integer, const Cmycomplex complex);
        friend istream& operator>>(istream& is, Cmycomplex& self);
        friend ostream& operator<<(ostream& os, const Cmycomplex& self);
};

istream& operator>>(istream& is, Cmycomplex& self)
{
    double r, i;
    is >> r >> i;
    self.real = r;
    self.imag = i;
    return is;
}
ostream& operator<<(ostream& os, const Cmycomplex& self)
{
    os << 1.0 * self.real << ' ' << 1.0 * self.imag << endl;
    return os;
}

Cmycomplex operator*(int integer, const Cmycomplex complex)
{
    return complex * Cmycomplex(integer);
}

class Point
{
    public:
        Cmycomplex x, y;
        friend istream& operator>>(istream& is, Point& self);
};

istream& operator>>(istream& is, Point& self)
{
    Cmycomplex xx, yy;
    is >> xx >> yy;
    self.x = xx;
    self.y = yy;
    return is;
}

Cmycomplex calculate_det(Cmycomplex a, Cmycomplex b, Cmycomplex c,
                         Cmycomplex d, Cmycomplex e, Cmycomplex f,
                         Cmycomplex g, Cmycomplex h, Cmycomplex i)
{
    return a * e * i + b * f * g + d * h * c - g * e * c - d * b * i - f * h * a;
}

int main()
{
    Point p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    Cmycomplex x1 = p1.x, x2 = p2.x, x3 = p3.x;
    Cmycomplex y1 = p1.y, y2 = p2.y, y3 = p3.y;
    Cmycomplex det = (x2 - x1) * (x3 - x2) * (x3 - x1);
    Cmycomplex det_a = calculate_det(y1, x1, 1,
                                     y2, x2, 1,
                                     y3, x3, 1);
    Cmycomplex det_b = calculate_det(x1 * x1, y1, 1,
                                     x2 * x2, y2, 1,
                                     x3 * x3, y3, 1);
    Cmycomplex det_c = calculate_det(x1 * x1, x1, y1,
                                     x2 * x2, x2, y2,
                                     x3 * x3, x3, y3);
    Cmycomplex a = Cmycomplex(0) - det_a / det;
    Cmycomplex b = Cmycomplex(0) - det_b / det;
    Cmycomplex c = Cmycomplex(0) - det_c / det;
    a.display();
    b.display();
    c.display();
}


