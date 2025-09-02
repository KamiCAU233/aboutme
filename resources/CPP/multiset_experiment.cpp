#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    multiset<int> ms;
    set<int> once_in_set;
    for (int i = 0; i < n; i++) {
        string method;
        int operand;
        cin >> method >> operand;
        if (method == "add") {
            once_in_set.insert(operand);
            ms.insert(operand);
            cout << ms.count(operand) << endl;
        } else if (method == "del") {
            cout << ms.count(operand) << endl;
            ms.erase(operand);
        } else if (method == "ask") {
            cout << (int)(once_in_set.find(operand) != once_in_set.end()) << ' ' << ms.count(operand) << endl;
        }
    }

}


