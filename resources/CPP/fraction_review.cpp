#include <iostream>
#include <cmath>
using namespace std;

int get_gcd(int a, int b)
{
    for (int i = a; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return -1;
}

class Fraction {
    public:
        Fraction(int up = 1, int low = 1) : upper(up), lower(low) {}

        Fraction operator-(const Fraction a) const {
            int new_upper = upper * a.lower - lower * a.upper;
            int new_lower = a.lower * lower;
            return Fraction(new_upper, new_lower);
        }
        friend bool operator==(Fraction a, Fraction b);
        friend bool operator!=(Fraction a, Fraction b);
        friend ostream& operator<<(ostream& os, const Fraction& self);
        friend istream& operator>>(istream& is, Fraction& self);
    private:
        int upper, lower;
};

bool operator!=(Fraction a, Fraction b) {
    return (b.upper * a.lower - b.lower * a.upper != 0);
}

ostream& operator<<(ostream& os, const Fraction& self) {
    int sign = (self.upper * self.lower) > 0 ? 1 : (-1);
    int gcd = get_gcd(abs(self.upper), abs(self.lower));
    int new_upper = self.upper / gcd;
    int new_lower = self.lower / gcd;
    os << sign * abs(new_upper) << '/' << abs(new_lower);
    return os;
}
istream& operator>>(istream& is, Fraction& self) {
    int up, low;
    is >> up >> low;
    self.upper = up;
    self.lower = low;
    return is;
}


//StudybarCommentBegin
int main(int argc, char *argv[]) {
    Fraction a(1, 2), b;
    Fraction const c(1,-2);
    cout << a << "\n" << b << "\n" << c << '\n';
    cin >> a >> b;

    if (c != b)
        cout << "!=" << endl;
    else
    	cout << "==" << endl;

    cout <<c<<" - "<<a<<" = "<< c - a <<endl ;
    return 0;
}
//StudybarCommentEnd
