#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<pii> v(n);
    vector<int> w(n);

    for (int i {}; i <= n; ++i) {
        if (i == 0) {
            int x;

            cin >> x;

            v[i].first = x;

            continue;
        } else if (i == n) {
            cin >> v[i - 1].second;
            
            continue;
        }

        cin >> v[i].first;

        v[i - 1].second = v[i].first;
    }

    for (int &x : w) {
        cin >> x;
    }

    double ans {};

    for (int i {}; i < n; ++i) {
        auto [f, s] = v[i];

        int minv {min(f, s)};

        ans += w[i] * minv;
        ans += (w[i] * abs(f - s)) / 2.0;
    }

    cout << fixed << setprecision(1) << ans << '\n';

    return 0;
}