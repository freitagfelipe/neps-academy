#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    ll ans {};

    for (int i {1}; i <= m; ++i) {
        int r {n - i};

        if (2 * m < r) {
            continue;
        }

        int minv {max(1, r - m)}, maxv {min(r - 1, m)};

        ans += maxv - minv + 1;
    }
    
    cout << ans << '\n';

    return 0;
}