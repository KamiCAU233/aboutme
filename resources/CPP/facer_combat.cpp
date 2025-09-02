#include <cmath>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<int, int> dict;
    for (int i = 0; i < n; i++) {
        int p, v;
        cin >> p >> v;
        dict[p] = v;
    }
    dict[1] = 100000000;
    for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++) {
        int min_difference = 2147483646;
        bool min_isStronger = false;
        int min_opponent = 0;
        for (map<int, int>::iterator jt = dict.begin(); jt != dict.end(); jt++) {
            if (it->first > jt->first) {
                int the_difference = abs(it->second - jt->second);
                if (the_difference < min_difference) {
                    min_difference = the_difference;
                    min_isStronger = ((it->second - jt->second) > 0);
                    min_opponent = jt->first;
                } else if (the_difference == min_difference) {
                    if (min_isStronger == false && (it->second - jt->second) > 0) {
                        min_isStronger = true;
                        min_opponent = jt->first;
                    }
                }
            }
        }
        if (it->first != 1) cout << it->first << ' ' << min_opponent <<  endl;
    }
}
