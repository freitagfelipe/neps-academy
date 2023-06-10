#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int ans {1};

    while (n > 1) {
        if (n & 1) {
            n *= 3;
            ++n;
        } else {
            n /= 2;
        }

        ++ans;
    }

    cout << ans << '\n';

    return 0;
}