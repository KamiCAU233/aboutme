#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int array[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100, -1};
    cin >> array[10];
    for (int iw = 0; iw < 10; iw++)
    {
        cout << setw(5) << array[iw];
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (array[i] < array[j] && i > j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int ii = 0; ii < 11; ii++)
    {
        cout << setw(5) << array[ii];
    }
    cout << endl;
}
