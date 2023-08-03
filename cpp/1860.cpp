#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> height(n + 1, 0);
    set<int> s;

    ll ans {};

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        auto it {s.upper_bound(x)};

        int p {};

        if (it != s.end()) {
            p = *it;
        }

        if (it != s.begin() && height[*(--it)] > height[p]) {
            p = *it;
        }

        s.insert(x);

        height[x] = height[p] + 1;

        ans += height[x];

        cout << ans << '\n';
    }

    return 0;
}