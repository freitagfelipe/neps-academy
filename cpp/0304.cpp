#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int ans {};

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        ans |= x;
    }

    cout << ans << '\n';

    return 0;
}