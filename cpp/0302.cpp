#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

#define MAXN 110

int p[MAXN], h[MAXN];

void build(int n) {
    for (int i {1}; i <= n; ++i) {
        p[i] = i;
    }
}

int find(int x) {
    if (p[x] == x) {
        return x;
    }

    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (h[x] < h[y]) {
        swap(x, y);
    }

    p[y] = x;

    if (h[x] == h[y]) {
        ++h[x];
    }
}

void kruskal(vector<tiii> &edges, int n) {
    build(n);

    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {
            merge(u, v);

            cout << u << " " << v << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t {};
    
    while (cin >> n >> m && n != 0) {
        vector<tiii> edges(m);

        for (auto &[w, u, v] : edges) {
            cin >> u >> v >> w;
        }

        cout << "Teste " << t + 1 << '\n';

        kruskal(edges, n);

        cout << '\n';
    }

    return 0;
}