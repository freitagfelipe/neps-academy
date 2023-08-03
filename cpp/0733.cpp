#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<pii> v(n);

    for (auto &[x, y] : v) {
        cin >> x >> y;
    }

    vector<int> hitted;
    vector<bool> already_hitted(n);

    int m;

    cin >> m;

    for (int i {}; i < m; ++i) {
        int x, y;

        cin >> x >> y;

        auto it {find(v.begin(), v.end(), make_pair(x, y))};

        if (it != v.end() && !already_hitted[it - v.begin()]) {
            hitted.push_back(it - v.begin());

            already_hitted[it - v.begin()] = true;
        }
    }

    sort(hitted.begin(), hitted.end());

    int c {};

    for (int h : hitted) {
        if (c++ > 0) {
            cout << " ";
        }

        cout << h;
    }

    cout << '\n';

    return 0;
}