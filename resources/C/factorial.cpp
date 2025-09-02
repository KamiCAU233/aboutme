#include <iostream>
using namespace std;

int fac(int n);

int main(void)
{
    int n;
    cin >> n;
    cout << fac(n) << endl;
}

int fac(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fac(n - 1);
}
