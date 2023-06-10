#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 1010
#define INF int(1e9)

int n;
vector<pii> g[MAXN];
int dist[MAXN];
bitset<MAXN> marked;

void dijkstra(int s) {
    for (int i {}; i < n; ++i) {
        dist[i] = INF;
    }

    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        int curr {pq.top().second};

        pq.pop();

        if (marked[curr]) {
            continue;
        }

        marked[curr] = true;

        for (auto [w, neigh] : g[curr]) {
            if (dist[curr] + w < dist[neigh]) {
                dist[neigh] = dist[curr] + w;
                
                pq.push({dist[neigh], neigh});
            }
        }
    }
}

int main() {
    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int v, u, w;

        cin >> v >> u >> w;

        --v;
        --u;

        g[v].emplace_back(w, u);
        g[u].emplace_back(w, v);
    }

    int s;

    cin >> s;

    dijkstra(--s);

    int min_v {INF}, max_v {-1};

    for (int i {}; i < n; ++i) {
        if (i == s) {
            continue;
        }

        min_v = min(min_v, dist[i]);
        max_v = max(max_v, dist[i]);
    }

    cout << max_v - min_v << '\n';

    return 0;
}