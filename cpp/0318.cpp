#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

typedef long long ll;

int p[MAXN], h[MAXN], w[MAXN];
vector<tuple<int, int, int>> highways, railways;

void build(int n) {
    for (int i {1}; i <= n; ++i) {
        p[i] = i;
        w[i] = 1;
    }
}

int find(int x) {
    if (p[x] == x) {
        return x;
    }

    return p[x] = find(p[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (h[x] < h[y]) {
        swap(x, y);
    }

    p[y] = x;
    w[x] += w[y];

    if (h[x] == h[y]) {
        ++h[x];
    }
}

ll kruskal(int n) {
    ll cost {};

    sort(railways.begin(), railways.end());

    for (auto [w, u, v] : railways) {
        if (find(u) != find(v)) {
            join(u, v);

            cost += w;
        }
    }

    if (w[find(1)] == n) {
        return cost;
    }

    sort(highways.begin(), highways.end());

    for (auto [w, u, v] : highways) {
        if (find(u) != find(v)) {
            join(u, v);

            cost += w;
        }
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    build(n);

    int rw, hw;

    cin >> rw >> hw;

    for (int i {}; i < rw; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        railways.emplace_back(w, u, v);
    }

    for (int i {}; i < hw; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        highways.emplace_back(w, u, v);
    }

    cout << kruskal(n) << '\n';

    return 0;
}