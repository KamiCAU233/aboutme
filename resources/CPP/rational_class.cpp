#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int getGCD(int, int);

class Rational {
    private:
        int numer, denom;
    public:
        Rational(int n = 1, int d = 1) {
            numer = n;
            denom = d;
            getReduced();
        }

        void getReduced() {
            int gcd = getGCD(abs(numer), abs(denom));
            numer /= gcd;
            denom /= gcd;
            if (denom < 0) {
                denom = - denom;
                numer = - numer;
            }
        }

        void add(Rational r1, Rational r2) {
            Rational r(r1.numer * r2.denom + r1.denom * r2.numer , r1.denom * r2.denom);
            r.getReduced();
            *this = r;
        }
        void minus(Rational r1, Rational r2) {
            Rational r(r1.numer * r2.denom - r1.denom * r2.numer , r1.denom * r2.denom);
            r.getReduced();
            *this = r;
        }
        void multi(Rational r1, Rational r2) {
            Rational r(r1.numer * r2.numer, r1.denom * r2.denom);
            r.getReduced();
            *this = r;
        }
        void divide(Rational r1, Rational r2) {
            Rational r(r1.numer * r2.denom, r1.denom * r2.numer);
            r.getReduced();
            *this = r;
        }
        void printFormal() const {
            cout << numer << '/' << denom << endl;
        }
        void printFixed() const {
            cout << fixed << setprecision(2) << (1.0 * numer / denom) << endl;;
        }
        void printBoth() const {
            cout << "the Formal format of the rational is : ";
            printFormal();
            cout << "the Fixed format of the rational is : ";
            printFixed();
        }
};

int getGCD(int x, int y) {
    for (int i = x; i > 0; i--) {
        if (x % i == 0 && y % i == 0) {
            return i;
        }
    }
    cout << "Greatest Common Divisor Error!";
    return -1;
}


//StudybarCommentBegin
int main()
{
    int firstN,firstD,secondN,secondD;
    char op;

//    cout<<"Please input the numerator of first Rational: ";
    cin>>firstN;
//    cout<<"Please input the denominator of first Rational: ";
    cin>>firstD;
//    cout<<"Please input the numerator of second Rational: ";
    cin>>secondN;
//    cout<<"Please input the denominator of second Rational: ";
    cin>>secondD;


    Rational r1(firstN,firstD),r2(secondN,secondD),r3;


    cin>>op;

    cout<<"the Formal format of the first rational is : ";
    r1.printFormal();
    cout<<"the Formal format of the second rational is : ";
    r2.printFormal();
    cout<<endl;

    switch(op)
    {
        case '+' :
            r3.add(r1,r2);
            r3.printBoth();
            break;
        case '-' :
            r3.minus(r1,r2);
            r3.printBoth();
            break;
        case '*':
            r3.multi(r1,r2);
            r3.printBoth();
            break;
        case '/':
            r3.divide(r1,r2);
            r3.printBoth();
            break;
        default:
            cout<<"Invalid operator!";
    }

    return 0;
}
//StudybarCommentEnd
