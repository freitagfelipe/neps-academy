#include <bits/stdc++.h>

using namespace std;

#define MAXN 5010

typedef long long ll;

vector<tuple<int, int, int>> edges;
int p[MAXN], h[MAXN], w[MAXN];

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

void build(int n) {
    for (int i {1}; i <= n; ++i) {
        p[i] = i;
        w[i] = 1;
    }
}

ll kruskal(int n) {
    sort(edges.rbegin(), edges.rend());

    ll cost {};

    for (auto [weight, u, v] : edges) {
        if (find(u) != find(v)) {
            join(u, v);

            cost += weight;
        } else if (w[find(u)] == n) {
            cost += weight;

            break; 
        }
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    build(n);

    for (int i {}; i < m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        edges.emplace_back(w, u, v);
    }

    cout << kruskal(n) << '\n';

    return 0;
}