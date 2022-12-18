#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN int(1e6 + 10)

int n;
vector<int> g[MAXN];
int dist[MAXN];
bool marked[MAXN];

void dfs(int curr) {
    marked[curr] = true;

    for (int v : g[curr]) {
        if (!marked[v]) {
            dist[v] = dist[curr] + 1;

            dfs(v);
        }
    }
}

int get_farthest(int s) {
    dist[s] = 0;

    dfs(s);

    int max_dist {};
    int farthest_node {s};

    for (int i {1}; i <= n; ++i) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_node = i;
        }
    }

    return farthest_node;
}

int get_diameter() {
    int x {get_farthest(1)};

    memset(dist, 0, sizeof(dist));
    memset(marked, 0, sizeof(marked));

    int y {get_farthest(x)};

    return dist[y];
}

int main() {
    cin >> n;

    for (int i {}; i < n - 1; ++i) {
        int x, y;

        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << get_diameter() << '\n';

    return 0;
}
