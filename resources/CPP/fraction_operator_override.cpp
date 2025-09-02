#include <iostream>
using namespace std;

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
        void Show()
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

void fswap(Fraction& a, Fraction& b)
{
    Fraction temp = a;
    a = b;
    b = temp;
}


//StudybarCommentBegin
int main(int argc, char *argv[]) {
	int x,y;
	cin>>x>>y;
    Fraction a(1,x),b(1,y),c(2);
    fswap(a,b);
    a.Show(); cout<<endl;
    c.Show(); cout<<endl;
    c=b-a;
    c.Show();
    return 1;
}
//StudybarCommentEnd
