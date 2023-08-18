#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<pii> v(n);

    int idx {1};

    for (auto &[f, s] : v) {
        int calc {};

        for (int i {}; i < m; ++i) {
            int x;

            cin >> x;

            calc += x;
        }

        f = calc;
        s = idx++;
    }

    sort(v.begin(), v.end());

    v.resize(3);

    for (auto [f, s] : v) {
        cout << s << '\n';
    }

    return 0;
}
