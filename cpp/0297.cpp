#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 1010
#define INF int(1e9)

int n;
vector<pii> g[MAXN];
int dist[MAXN];
bool marked[MAXN];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i {1}; i <= n + 1; ++i) {
        dist[i] = INF;
    }

    pq.push({0, 0});

    dist[0] = 0;

    for (int i {}; i <= n + 1; ++i) {
        int current {-1};

        while (!pq.empty()) {
            current = pq.top().second;

            pq.pop();

            if (!marked[current]) {
                break;
            }
        }

        if (current == -1) {
            break;
        }

        marked[current] = true;

        for (auto [w, nb] : g[current]) {
            if (dist[nb] > dist[current] + w) {
                dist[nb] = dist[current] + w;

                pq.push({dist[nb], nb});
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

    cout << dist[n + 1] << '\n';

    return 0;
}
