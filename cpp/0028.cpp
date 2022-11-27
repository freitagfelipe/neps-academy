#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 110
#define INF int(1e9)

typedef pair<int, int> pii;

int n;
vector<pii> g[MAXN];
int dist[MAXN];
bool marked[MAXN];

void dijkstra() {
    for (int i {1}; i <= n; ++i) {
        dist[i] = INF;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;

    pq.push({0, 1});

    for (int i {1}; i <= n; ++i) {
        int curr {-1};

        while (!pq.empty()) {
            curr = pq.top().second;

            pq.pop();

            if (!marked[curr]) {
                break;
            }
        }

        if (curr == -1) {
            break;
        }

        marked[curr] = true;

        for (auto [w, n] : g[curr]) {
            if (dist[curr] + w < dist[n]) {
                dist[n] = dist[curr] + w;

                pq.push({dist[n], n});
            }
        }
    }
}

int main() {
    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int x, y, w;

        cin >> x >> y >> w;

        g[x].push_back({w, y});
        g[y].push_back({w, x});
    }

    dijkstra();

    cout << dist[n] << '\n';

    return 0;
}
