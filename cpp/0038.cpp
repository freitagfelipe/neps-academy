#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

typedef pair<int, int> pii;

vector<pii> g[MAXN];
int ans {-1};

void dfs(int u, int dest, int d = 0, int p = -1) {
    if (u == dest) {
        ans = d;

        return;
    } else if (ans != -1) {
        return;
    }

    for (auto [to, w] : g[u]) {
        if (to != p) {
            dfs(to, dest, d + w, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;

    cin >> n >> a >> b;

    for (int i {}; i < n - 1; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(a, b);

    cout << ans << '\n';

    return 0;
}
