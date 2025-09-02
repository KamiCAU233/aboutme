#include <iostream>
using namespace std;

class Fraction
{
    public:
        int numer, denom;
        Fraction(int x, int y = 1)
        {
            numer = x;
            denom = y;
        }
        void show()
        {
            cout << numer << "/" << denom;
        }
        double to_double()
        {   
            return numer * 1.0 / denom;
        }
};

void ifLessSwap(Fraction &a, Fraction &b)
{
    if (a.to_double() < b.to_double())
    {
        swap(a, b);
    }
}
//StudybarCommentBegin
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c;
	Fraction f1(a,b),f2(c);
	cout<<f1.to_double()<<endl;

	f1.show(); cout<<endl;
	f2.show(); cout<<endl;

	ifLessSwap(f1,f2);

	f1.show(); cout<<endl;
	f2.show(); cout<<endl;
}
//StudybarCommentEnd
