#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<pair<int, int>> v(n);

    for (auto &[e, s] : v) {
        cin >> s >> e;
    }

    sort(v.begin(), v.end());

    int last {v[0].first}, ans {1};

    for (int i {1}; i < n; ++i) {
        auto [e, s] = v[i];

        if (s < last) {
            continue;
        }

        ++ans;

        last = e;
    }

    cout << ans << '\n';

    return 0;
}