#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int ans {};

    while (cin >> n && n != 0) {
        ans = max(ans, n);
    }

    cout << ans << '\n';

    return 0;
}