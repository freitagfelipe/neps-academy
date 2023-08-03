#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

vector<int> g[MAXN];
bitset<MAXN> marked;

void dfs(int v) {
    marked[v] = true;

    for (int u : g[v]) {
        if (!marked[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t {};

    while (cin >> n >> m && n != 0) {
        cout << "Teste " << ++t << '\n';

        for (int i {}; i < m; ++i) {
            int v, u;

            cin >> v >> u;

            --v;
            --u;

            g[v].push_back(u);
            g[u].push_back(v);
        }

        int comp {};

        for (int i {}; i < n; ++i) {
            if (!marked[i]) {
                ++comp;

                dfs(i);
            }
        }

        comp == 1 ? cout << "normal\n\n" : cout << "falha\n\n";

        marked.reset();

        for (int i {}; i < n; ++i) {
            g[i].resize(0);
        }
    }

    return 0;
}