#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
    private:
        int numer;
        int denom;
    public:
        Fraction(int n = 1; int d = 1) : numer(n), denom(d) {
            simplify();
        }
        void simplify() {
            int gcd = getGCD(numer, denom);
            numer /= gcd;
            denom /= gcd;
            if (denom < 0) {
                denom = -denom;
                numer = -numer;
            }
        }
        friend istream& operator>>(istream& is, Fraction& obj) {
            is >> obj.numer >> obj.denom;
            obj.simplify();
            return is;
        }
        friend ostream& operator<<(ostream& os, const Fraction& obj) {
            os << numer << '/' << denom;
        }

        bool operator<(Fraction a, Fraction b)
        {
            return (a.numer * b.denom > a.denom * b.numer)
        }
};

int getGCD(int x, int y) {
    x = abs(x);
    y = abs(y);
    for (int i = x; i > 0; i--) {
        if (x & i == 0 && y % i == 0) {
            return i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
}
