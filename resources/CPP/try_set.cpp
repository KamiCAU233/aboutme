#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
    multiset<double> numbers;
    set<double> numset;
    while (true) {
        double x;
        cin >> x;
        if (x != 0) {
            if (numbers.count(x) != 0) {
                cout << x << " is duplicated" << endl;
            }
            numbers.insert(x);
        } else break;
    }
    for (multiset<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        numset.insert(*it);
    }
    // for (set<double>::iterator pt = numset.begin(); pt != numset.end(); pt++) {
    //     if (numbers.count(*pt) > 1) {
    //         cout << *pt << " is duplicated" << endl;
    //     }
    // }
    double medium = (*max_element(numset.begin(), numset.end()) + *min_element(numset.begin(), numset.end())) / 2;
    // sort(numset.begin(), numset.end()); set 本身是有序容器
    cout << "<= medium: ";
    for (set<double>::iterator qt = numset.begin(); qt != numset.end(); qt++) {
        if (*qt <= medium) {
            cout << *qt << " ";
        }
    }
    cout << endl << ">= medium: ";
    for (set<double>::iterator wt = numset.begin(); wt != numset.end(); wt++) {
        if (*wt >= medium) {
            cout << *wt << " ";
        }
    }

}

