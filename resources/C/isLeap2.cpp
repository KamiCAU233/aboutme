#include <iostream>
using namespace std;

char isLeap(int n);

int main()
{
    int n;
    cin >> n;
    cout << isLeap(n) << endl;
}

char isLeap(int n)
{
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
    {
        return 'y';
    }
    return 'n';
}
