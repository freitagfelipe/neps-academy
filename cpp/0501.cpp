#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e4 + 10)

int n;
vector<int> g[MAXN], gt[MAXN], ts, comp(MAXN, -1);
bitset<MAXN> visited;

void ts_dfs(int v) {
    visited[v] = true;

    for (int u : g[v]) {
        if (!visited[u]) {
            ts_dfs(u);
        }
    }

    ts.push_back(v);
}

void comp_dfs(int v, int c) {
    comp[v] = c;

    for (int u : gt[v]) {
        if (comp[u] == -1) {
            comp_dfs(u, c);
        }
    }
}

bool scc() {
    for (int i {}; i < n; ++i) {
        if (!visited[i]) {
            ts_dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());

    int c {};

    for (int v : ts) {
        if (comp[v] == -1) {
            comp_dfs(v, c++);
        }
    }

    return c == 1;
}

int main() {
    cin >> n;

    for (int i {}; i < n; ++i) {
        int v, u;

        cin >> v >> u;

        --v;
        --u;

        g[v].push_back(u);
        gt[u].push_back(v);
    }

    scc() ? cout << "S\n" : cout << "N\n";

    return 0;
}