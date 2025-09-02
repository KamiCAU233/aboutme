#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    vector<int> odd;
    vector<int> even;
    while (true) {
        char x[3];
        cin >> x;
        if (isdigit(x[0])) {
            int n = atoi(x);
            if (n % 2 == 1) odd.push_back(n);
            else even.push_back(n);
        } else {
            break;
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    for (vector<int>::iterator it = odd.begin(); it != odd.end(); it++) {
        cout << *it << ' ';
    }
    for (vector<int>::iterator it = even.begin(); it != even.end(); it++) {
        cout << *it << ' ';
    }
}
