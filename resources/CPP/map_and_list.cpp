#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<int, list<int>> List;
    for (int i = 0; i < n; i++) {
        string method;
        int operand;
        int operand2;
        cin >> method >> operand;
        if (method == "new") {
            List[operand] = {};
        } else if (method == "add") {
            cin >> operand2;
            List[operand].push_back(operand2);
        } else if (method == "merge") {
            cin >> operand2;
            List[operand].merge(List[operand2]);
            List[operand2].clear();
        } else if (method == "unique") {
            List[operand].sort();
            List[operand].unique();
        } else if (method == "out") {
            List[operand].sort();
            for (list<int>::iterator it = List[operand].begin(); it != List[operand].end(); it++) {
                cout << *it << ' ';
            }
        }
    }
}
