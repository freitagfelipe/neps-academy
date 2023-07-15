#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 50010

int n, lg, timer {};
int dist[MAXN];
vector<int> g[MAXN], tin(MAXN), tout(MAXN);
vector<vector<int>> up;

void dfs(int u, int p, int d = 0) {
    dist[u] = d;
    tin[u] = ++timer;
    up[u][0] = p;

    for (int i {1}; i <= lg; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int to : g[u]) {
        if (to == p) {
            continue;
        }

        dfs(to, u, d + 1);
    }

    tout[u] = ++timer;
}

void build(int root) {
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

    cin >> n;

    vector<vector<int>> equals(n / 2);

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        equals[x - 1].push_back(i);
    }

    for (int i {}; i < n - 1; ++i) {
        int u, v;

        cin >> u >> v;

        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    build(0);

    ll ans {};

    for (vector<int> &v : equals) {
        ans += dist[v[0]] + dist[v[1]] - 2 * dist[lca(v[0], v[1])];
    }

    cout << ans << '\n';

    return 0;
}