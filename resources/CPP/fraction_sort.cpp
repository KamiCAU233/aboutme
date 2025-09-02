#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int getGCD(int a, int b)
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

class Fraction
{
    private:
        int denom, numer;
    public:
        double get_value() const
        {
            return numer * 1.0 / denom;
        }
        Fraction(int n = 1, int d = 1)
        {
            denom = d;
            numer = n;
        }
        Fraction operator+(Fraction& other) const
        {
            int new_n = denom * other.numer + numer * other.denom;
            int new_d = denom * other.denom;
            return Fraction(new_n, new_d);
        }
        Fraction operator-(Fraction& other) const
        {
            int new_n = numer * other.denom - other.numer * denom;
            int new_d = denom * other.denom;
            return Fraction(new_n, new_d);
        }
        Fraction operator*(Fraction& other) const
        {
            int new_n = numer * other.numer;
            int new_d = denom * other.denom;
            return Fraction(new_n, new_d);
        }
        Fraction operator/(Fraction& other) const
        {
            int new_n = numer * other.denom;
            int new_d = denom * other.numer;
            return Fraction(new_n, new_d);
        }
        bool operator==(Fraction& other)
        {
            return numer * other.denom == denom * other.numer;
        }
        bool operator!=(Fraction& other)
        {
            return numer * other.denom != denom * other.numer;
        }
        bool operator<(Fraction& other)
        {
            Fraction self(numer, denom);
            return ((self - other).get_value() < 0);
        }
        bool operator>(Fraction& other)
        {
            return !operator<(other);
        }
        bool operator>=(Fraction& other)
        {
            return operator>(other) || operator==(other);
        }
        bool operator<=(Fraction& other)
        {
            return operator<(other) || operator==(other);
        }
        friend ostream& operator<<(ostream& os, const Fraction& x);
        friend istream& operator>>(istream& is, Fraction& x);

};


ostream& operator<<(ostream& os, const Fraction& x)
{
    int numer = x.numer;
    int denom = x.denom;
    if (x.get_value() < 0)
    {
        os << "-";
        numer = abs(x.numer);
        denom = abs(x.denom);
    }
    int gcd = getGCD(numer, denom);
    if (denom / gcd == 1)
    {
        os << (numer / gcd);
    }
    else
    {
        os << (numer / gcd) << '/' << (denom / gcd);
    }
    return os;
}

istream& operator>>(istream& is, Fraction& x)
{
    is >> x.numer >> x.denom;
    return is;
}

int main() {
    int n;
    cin >> n;
    vector<Fraction> fracs;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Fraction fr(a, b);
        fracs.push_back(fr);
    }
    sort(fracs.begin(), fracs.end());
    for (vector<Fraction>::iterator it = fracs.begin(); it != fracs.end(); it++) {
        cout << *it << endl;
    }
}
