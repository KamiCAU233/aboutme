#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    int arr[20];
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }
    set<int> s;
    for (int i = 0; i < 20; i++) {
        s.insert(arr[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ' ';
    }
}
