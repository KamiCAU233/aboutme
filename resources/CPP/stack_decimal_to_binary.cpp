#include <iostream>
#include <stack>
using namespace std;


int main(void) {
    int n;
    cin >> n;
    stack<int> binary;
    while (n != 0) {
        binary.push(n % 2);
        n = n / 2;
    }
    while (!binary.empty()) {
        cout << binary.top();
        binary.pop();
    }
}
