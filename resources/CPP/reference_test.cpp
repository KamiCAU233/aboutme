#include <iostream>
using namespace std;

void modify(int* ptr) {
    *ptr += 10;
}

void modify(int& ref) {
    ref += 5;
}

int main() {
    int x = 100;
    modify(&x);
    modify(x);
    cout << x << endl;
}
