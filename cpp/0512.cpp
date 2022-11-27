#include <iostream>
#include <vector>

using namespace std;

#define MAXN int(5 * 1e4)

bool visited[MAXN];
vector<int> g[MAXN];

void dfs(int i) {
    visited[i] = true;

    for (int n : g[i]) {
        if (!visited[n]) {
            dfs(n);
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int x, y;

        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans {};

    for (int i {1}; i <= n; ++i) {
        if (!visited[i]) {
            ++ans;

            dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}
