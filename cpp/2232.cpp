#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cout << "[";

    int c {};

    while (cin >> n) {
        if (n & 1) {
            n *= 3;
        } else {
            n *= 2;
        }

        if (c++ > 0) {
            cout << ", ";
        }

        cout << n;
    }

    cout << "]\n";

    return 0;
}