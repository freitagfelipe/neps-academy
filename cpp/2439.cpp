#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5 + 10)

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, lg, timer {}; 
vector<pii> g[MAXN];
vector<int> tin, tout, p, h;
vector<vector<int>> up, minv;
vector<tiii> edges;

void dfs(int u, int p, int w) {
    tin[u] = ++timer;

    up[u][0] = p;
    minv[u][0] = w;

    for (int i {1}; i <= lg; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        minv[u][i] = min(minv[u][i - 1], minv[up[u][i - 1]][i - 1]);
    }

    for (auto [to, w] : g[u]) {
        if (to == p) {
            continue;
        }

        dfs(to, u, w);
    }

    tout[u] = ++timer;
}

void build(int s) {
    lg = ceil(log2(n));
    up.assign(n + 1, vector<int>(lg + 1));
    minv.assign(n + 1, vector<int>(lg + 1));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);

    dfs(s, s, 0);
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    } else if (is_ancestor(v, u)) {
        return v;
    }

    for (int i {lg}; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}

int go(int u, int v) {
    int ans {INT_MAX};

    for (int i {lg}; i >= 0; --i) {
        if (tin[v] < tin[up[u][i]]) {
            ans = min(ans, minv[u][i]);

            u = up[u][i];
        }
    }

    return min(ans, minv[u][0]);
}

int query(int u, int v) {
    int lca_ans {lca(u, v)};

    if (lca_ans == u) {
        return go(v, lca_ans);
    } else if (lca_ans == v) {
        return go(u, lca_ans);
    }

    return min(go(u, lca_ans), go(v, lca_ans));
}

int find(int x) {
    if (p[x] == x) {
        return x;
    }

    return p[x] = find(p[x]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return;
    }

    if (h[u] < h[v]) {
        swap(u, v);
    }

    p[v] = u;

    if (h[u] == h[v]) {
        ++h[u];
    }
}

void build_dsu() {
    p.resize(n + 1);
    h.assign(n + 1, 0);

    for (int i {1}; i <= n; ++i) {
        p[i] = i;
    }
}

void kruskal() {
    build_dsu();

    sort(edges.rbegin(), edges.rend());

    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {
            join(u, v);

            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        edges.emplace_back(w, u, v);
    }

    kruskal();

    build(1);

    int q;

    cin >> q;

    while (q--) {
        int u, v;

        cin >> u >> v;

        cout << query(u, v) << '\n';
    }

    return 0;
}
