#include <iostream>
using namespace std;


int get_zdgys(int a, int b)
{
    for (int i = a; i > 0; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            return i;
        }
    }
    return 1;
}

class Fraction
{
    private:
        int fenzi;
        int fenmu;
    public:
        Fraction(int zi = 1, int mu = 1)
        {
            fenzi = zi;
            fenmu = mu;
        }
        Fraction operator+(Fraction other) const
        {
            int new_fenzi = fenzi * other.fenmu + fenmu * other.fenzi;
            int new_fenmu = fenmu * other.fenmu;
            return Fraction(new_fenzi, new_fenmu);
        }

        Fraction operator*(Fraction other) const
        {
            int new_fenzi = fenzi * other.fenzi;
            int new_fenmu = fenmu * other.fenmu;
            return Fraction(new_fenzi, new_fenmu);
        }
        void Show()
        {
            cout << fenzi << '/' << fenmu << endl;
        }
        friend ostream& operator<<(ostream& os, const Fraction self);
};

ostream& operator<<(ostream& os, const Fraction self)
{
    int zuidagongyinshu = get_zdgys(self.fenzi, self.fenmu);
    os << (self.fenzi / zuidagongyinshu) << '/' << (self.fenmu / zuidagongyinshu) << endl;
    return os;
}

int main()
{
    Fraction a(4, 3);
    Fraction b(2, 3);
    cout << (a + b);
}
