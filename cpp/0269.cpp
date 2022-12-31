#include <iostream>

using namespace std;

bool is_prime(int n) {
    for (int i {2}; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    cin >> n;

    int count {};

    for (int i {2}; i <= n; ++i) {
        if (is_prime(i)) {
            if (count++ > 0) {
                cout << " ";
            }

            cout << i;
        }
    }

    cout << '\n';

    return 0;
}
