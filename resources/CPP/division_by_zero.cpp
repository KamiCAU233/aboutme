#include <iostream>
using namespace std;

int main(void) {
    double a, b;
    int x;
    cin >> a >> b;
    try {
        if (b == 0) throw -1;
        cout << a / b;
    } catch(int x) {
        cout << "Attempted to divide by zero!";
    }
}
