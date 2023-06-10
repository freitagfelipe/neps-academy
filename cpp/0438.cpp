#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;

    cin >> n >> t;

    for (int i {1}; i < n; ++i) {
        int x;

        cin >> x;

        if (x > t) {
            cout << "N\n";

            return 0;
        }
    }

    cout << "S\n";

    return 0;
}