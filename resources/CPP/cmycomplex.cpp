#include <iostream>
using namespace std;

class Cmycomplex {
    private:
        int real, imag;
    public:
        Cmycomplex(int r = 0, int i = 0) : real(r), imag(i) {}
        void Show() const {
            cout << "(" << real;
            cout << '+' << imag << 'i' << ')';

        }
        void Set(int r, int i) {
            real = r;
            imag = i;
        }
        const Cmycomplex operator+(const Cmycomplex& other) const {
            return Cmycomplex(real + other.real, imag + other.imag);
        }
        const Cmycomplex operator-(const Cmycomplex& other) const {
            return Cmycomplex(real - other.real, imag - other.imag);
        }
        const Cmycomplex operator*(const Cmycomplex& other) const {
            int r = real * other.real - imag * other.imag;
            int i = real * other.imag + imag * other.real;
            return Cmycomplex(r, i);
        }

};

//StudybarCommentBegin
int main()
{
Cmycomplex  z1(3,4),z2(7),z3;
double  x,y;
cin>>x>>y;
z2.Set(x,y);
z3=z1+z2;
cout<<"\n";
z3.Show();
z3=z1-z2;
cout<<"\n";
z3.Show();
z3=z1*z2;
cout<<"\n";
z3.Show();

}
//StudybarCommentEnd
