#include <bits/stdc++.h>

using namespace std;

bool prime_test(int n) {
    if (n < 2) {
        return false;
    }

    for (int i {2}; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (; n >= 2; --n) {
        if (prime_test(n)) {
            cout << n << '\n';

            break;
        }
    }

    return 0;
}
