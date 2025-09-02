#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string expr = "";
    cin >> expr;
    stack<char> st;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) {
                cout << "false";
                return 0;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        cout << "true";
        return 1;
    }
    cout << "false";
    return 0;
}
