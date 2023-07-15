#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN int(1e5) + 10

int n, lg, timer {};
ll dist[MAXN];
vector<vector<int>> g, up;
vector<int> tin(MAXN), tout(MAXN);

void dfs(int u, int p) {
    dist[u] += dist[p];
    tin[u] = ++timer;
    up[u][0] = p;

    for (int i {1}; i <= lg; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int to : g[u]) {
        if (to == p) {
            continue;
        }

        dfs(to, u);
    }

    tout[u] = ++timer;
}

void build(int root) {
    timer = 0;
    lg = ceil(log2(n));
    up.assign(n, vector<int>(lg + 1));

    dfs(root, root);
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n != 0) {
        g.assign(n, vector<int>());

        for (int i {1}; i <= n - 1; ++i) {
            int u, d;

            cin >> u >> d;

            g[u].push_back(i);
            g[i].push_back(u);

            dist[i] = d;
        }

        build(0);

        int q;

        cin >> q;

        while (q--) {
            int u, v;

            cin >> u >> v;

            cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << " \n"[q == 0];
        }
    }


    return 0;
}