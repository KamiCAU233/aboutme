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
        Cmycomplex sqrt() const
        {
            double r = std::sqrt(real * real + imag * imag);
            double new_real, new_imag;
            if (imag == 0) {
                if (real >= 0) {
                    new_real = std::sqrt(real);
                    new_imag = 0;
                } else {
                    new_real = 0;
                    new_imag = std::sqrt(-real);
                }
            } else {
                double sign = (imag >= 0) ? 1 : -1;
                new_real = std::sqrt((r + real) / 2);
                new_imag = sign * std::sqrt((r - real) / 2);
            }
            return Cmycomplex(new_real, new_imag);
        }
        friend Cmycomplex operator*(int integer, const Cmycomplex complex);
};

Cmycomplex operator*(int integer, const Cmycomplex complex)
{
    return complex * Cmycomplex(integer);
}


//StudybarCommentBegin
int main()
{
	double x1, x2, x3, y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	Cmycomplex a(x1, y1), b(x2, y2), c(x3, y3), z, t1, t2;

	z=b*b-4*a*c;

	t1=((-1)*b+z.sqrt())/(2*a);     //z.sqrt()为求复数z的平方根，这里的2*a涉及操作符重载，且友元重载。
	t2=((-1)*b-z.sqrt())/2.0/a;     //这里涉及到除法的重载

	if(t1.gety()>t2.gety())   //gety()为得到虚部值
	{
		t1.Show();
		t2.Show();
	}
	else
	{
		t2.Show();
		t1.Show();
	}
	return 0;
}
//StudybarCommentEnd
