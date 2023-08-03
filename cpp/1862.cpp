#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> g;

int solver(const vector<int> &preorder, int &idx, int minv, int maxv) {
    if (idx == (int) preorder.size()) {
        return 0;
    }

    int k {preorder[idx]};

    if (k < minv || k > maxv) {
        return 0;
    }

    ++idx;

    g[k].first = solver(preorder, idx, minv, k - 1);
    g[k].second = solver(preorder, idx, k + 1, maxv);

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    g.assign(n + 1, pii());

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int idx {};

    solver(v, idx, INT_MIN, INT_MAX);

    for (int i {1}; i <= n; ++i) {
        cout << g[i].first << " " << g[i].second << '\n';
    }

    return 0;
}