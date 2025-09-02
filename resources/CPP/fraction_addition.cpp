#include <iostream>
using namespace std;

int getGCD(int a, int b);

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int numerator = a * d + c * b;
    int denominator = b * d;
    char minus = 0;
    if (denominator < 0)
    {
        denominator = - denominator;
        minus = '-';
    }
    cout << minus << numerator / getGCD(numerator, denominator) << '/' << denominator / getGCD(numerator, denominator) << endl;
    return 0;
}

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


