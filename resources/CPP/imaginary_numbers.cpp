#include <iostream>
#include <cmath>
using namespace std;

class imaginary
{
    public:
        double a, b;  // a + bi
        imaginary() { }
        imaginary(double x)
        {
            a = x;
            b = 0;
        }
        imaginary(double x, double y)
        {
            a = x;
            b = y;
        }
        void show()
        {
            if (b >= 0) printf("(%.2lf+%.2lfi)", a, abs(b));
            else printf("(%.2lf-%.2lfi)", a, abs(b));
        }
        imaginary add(imaginary x)
        {
            return imaginary(a + x.a, b + x.b);
        }
        imaginary sub(imaginary x)
        {
            return imaginary(a - x.a, b - x.b);
        }
        imaginary mul(imaginary x)
        {
            return imaginary(a * x.a - b * x.b, b * x.a + a * x.b);
        }
        imaginary div(imaginary x)
        {
            double c = x.a;
            double d = x.b;
            double real = (a * c + b * d) / (c * c + d * d);
            double imag = (b * c - a * d) / (c * c + d * d);
            return imaginary(real, imag);
        }
};



int main()
{
    double a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    imaginary a(a1, a2);
    imaginary b(b1, b2);
    imaginary c(c1, c2);


    imaginary ima_delta = b.mul(b).sub(a.mul(c).mul(imaginary(4)));
    double delta_real = ima_delta.a;
    double delta_imag = ima_delta.b;
    double mag = sqrt(delta_real * delta_real + delta_imag * delta_imag);
    double sqrt_real = sqrt((mag + delta_real) / 2.0);
    double sqrt_imag = (delta_imag < 0 ? -1 : 1) * sqrt((mag - delta_real) / 2.0);
    imaginary sqrt_delta(sqrt_real, sqrt_imag);
    imaginary x1 = imaginary(0).sub(b).add(sqrt_delta).div(a.mul(imaginary(2)));
    imaginary x2 = imaginary(0).sub(b).sub(sqrt_delta).div(a.mul(imaginary(2)));
    if (x2.b > 0 && x1.b < 0)
    {
        // TO DO: swap two
        imaginary temp = x1;
        x1 = x2;
        x2 = temp;
    }
    x1.show();
    cout << endl;
    x2.show();
    cout << endl;
}
