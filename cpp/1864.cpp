#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> g;
vector<int> color;

int dfs(int u, bool &is_rbt) {
    if (u == 0) {
        return 0;
    }

    int lc {dfs(g[u].first, is_rbt)}, rc {dfs(g[u].second, is_rbt)};

    if (lc != rc || (color[u] == 0 && color[g[u].first] == 0) || (color[u] == 0 && color[g[u].second] == 0)) {
        is_rbt = false;
    }

    return lc + (color[u] == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        g.assign(n + 1, pii());
        color.assign(n + 1, 1);

        color[0] = 1;

        vector<bool> is_root(n + 1, true);

        for (int i {1}; i <= n; ++i) {
            int l, r, c;

            cin >> l >> r >> c;

            g[i].first = l;
            g[i].second = r;
            color[i] = c;

            is_root[l] = is_root[r] = false;
        }

        int root {};

        for (int i {1}; i <= n; ++i) {
            if (is_root[i]) {
                root = i;

                break;
            }
        }

        if (color[root] == 0) {
            cout << 0 << '\n';

            continue;
        }

        bool is_rbt {true};

        dfs(root, is_rbt);

        if (is_rbt) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}