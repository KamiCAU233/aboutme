#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int);

int main(void) {
    int N;
    cin >> N;
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); i++) {
        cout << fixed << setw(5) << primes[i];
        if (i % 10 == 9) {
            cout << endl;
        }
    }
}

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
