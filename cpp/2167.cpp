#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

typedef pair<int, int> pii;

set<int> g[MAXN];
bitset<MAXN> visited;

int calculate_dist(const pii &a, const pii &b) {
    return (abs(a.first - b.first) + abs(a.second - b.second)) * 100;
}

void dfs(int u) {
    visited[u] = true;

    for (int to : g[u]) {
        if (!visited[to]) {
            dfs(to);
        }
    }
}

int cc(int n) {
    int comp {};

    for (int i {}; i < n; ++i) {
        if (!visited[i]) {
            ++comp;

            dfs(i);
        }
    }

    return comp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n, maxw;

    cin >> x >> y >> n >> maxw;

    vector<pii> v(n);

    for (auto &[f, s] : v) {
        cin >> f >> s;
    }

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            if (j == i) {
                continue;
            }

            if (calculate_dist(v[i], v[j]) <= maxw) {
                g[i].insert(j);
                g[j].insert(i);
            }
        }
    }

    cout << cc(n) - 1 << '\n';

    return 0;
}