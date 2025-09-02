//StudybarCommentBegin
#include <iostream>
#include<string>
using namespace std;
//StudybarCommentEnd

void f2() {
    throw string("Exception from f2");
}

int f1(int a, int b) {
    if (b == 0) {
        throw string("You inputted:0");
    }
    try {
        f2();
    } catch (string e) {
        cout << "In f2 function" << endl;
        cout << e << endl;
    }
    return a % b;
}

int main() {
    double num1, num2;
    cin >> num1 >> num2;
    try {
        if ((num1 != (int)num1) || (num2 != (int)num2)) {
            throw string("Non-int was inputted, try again");
        }

        int result = f1(num1, num2);
        cout << num1 << "%" << num2 << "=" << result << endl;
        cout << "In f1 function" << endl;
    } catch (string e) {
        cout << e << endl;
    }
    cout << "In main function" << endl;
    return 0;
}
