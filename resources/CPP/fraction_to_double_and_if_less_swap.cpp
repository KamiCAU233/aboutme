#include <iostream>
using namespace std;
int getGCD(int a, int b)
{
    for (int i = b; i > 0; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            return i;
        }
    }
    return -1;
}
class Fraction
{
    private:
        int numer;
        int denom;
    public:
        Fraction(int num = 1, int den = 1)
        {
            numer = num;
            denom = den;
        }
        Fraction(double num)
        {
            numer = 1000 * num;
            denom = 1000;
            Simplify();
        }

        void Simplify()
        {
            int gcd = getGCD(numer, denom);
            if (gcd != -1)
            {
                numer /= gcd;
                denom /= gcd;
            }
        }
        double to_double()
        {
            return 1.0 * numer / denom;
        }

        void show()
        {
            cout << numer << "/" << denom << endl;
        }
        Fraction operator-(Fraction& other)
        {
            int new_denom = denom * other.denom;
            int new_numer = numer * other.denom - denom * other.numer;
            return Fraction(new_numer, new_denom);
        }
};


void ifLessSwap(Fraction& a, Fraction& b)
{
    if ((a - b).to_double() < 0)
    {
        Fraction temp = a;
        a = b;
        b = temp;
    }
}



//StudybarCommentBegin
int main()
{
	int a,b,c,d;
	double r;
	cin>>a>>b>>c>>r;
	Fraction f1(a,b),f2(c),f3(r);
	cout<<f1.to_double()<<endl;

	f1.show(); cout<<endl;
	f2.show(); cout<<endl;
	f3.show(); cout<<endl;

	ifLessSwap(f1,f3);

	f1.show(); cout<<endl;
	f3.show(); cout<<endl;
}
//StudybarCommentEnd
