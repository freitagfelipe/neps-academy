#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int ans {};

    for (int i {}; i < n; ++i) {
        int xr, yr, xt, yt;

        cin >> xr >> yr >> xt >> yt;

        int xdiff {xr - xt}, ydiff {yr - yt};

        ans += xdiff * xdiff + ydiff * ydiff;
    }

    cout << ans << '\n';

    return 0;
}