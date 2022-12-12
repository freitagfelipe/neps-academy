#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1010
#define INF int(1e9)

typedef pair<int, int> pii;

int n;
vector<pii> g[MAXN];
int dist[MAXN];
bool marked[MAXN];

int prim() {
    for (int i {}; i < n; ++i) {
        dist[i] = INF;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0] = 0;

    pq.push({0, 0});

    int mst_cost {};

    while (!pq.empty()) {
        int curr {pq.top().second};

        pq.pop();

        if (marked[curr]) {
            continue;
        }

        marked[curr] = true;
        mst_cost += dist[curr];

        for (auto [w, v] : g[curr]) {
            if (w < dist[v]) {
                dist[v] = w;

                pq.push({dist[v], v});
            }
        }
    }

    return mst_cost;
}

int main() {
    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    cout << prim() << '\n';

    return 0;
}
