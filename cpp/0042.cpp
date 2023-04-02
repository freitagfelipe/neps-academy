#include <iostream>
#include <vector>

using namespace std;

#define MAXN int(1e5 + 10)
#define INF 999999999

int n;
vector<int> g[MAXN];
bool visited[MAXN];
int answer {INF};

int dfs(int curr) {
    visited[curr] = true;

    int total_w {};

    for (auto neigh : g[curr]) {
        if (!visited[neigh]) {
            int r {dfs(neigh)};

            answer = min(answer, abs((n - r) - r));

            total_w += r;
        }
    }

    return total_w + 1;
}

int main() {
    cin >> n;

    for (int i {}; i < n - 1; ++i) {
        int v, u;

        cin >> v >> u;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(1);

    cout << answer << '\n';

    return 0;
}
