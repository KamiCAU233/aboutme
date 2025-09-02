#include <iostream>
using namespace std;
class Fraction
{
    private:
        int numer, denom;
    public:
        Fraction()
        {
            numer = 1;
            denom = 1;
        }
        Fraction(int n)
        {
            numer = n;
            denom = 1;
        }
        Fraction(int x, int y)
        {
            numer = x;
            denom = y;
        }
        void show()
        {
            cout << numer << "/" << denom;
        }
};

//StudybarCommentBegin
int main()
{
	Fraction f1,f2(2),f3(1,3);
	f1.show(); cout<<endl;
	f2.show(); cout<<endl;
	f3.show(); cout<<endl;
}
//StudybarCommentEnd
