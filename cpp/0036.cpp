#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 10010
#define INF int(1e9)

int n;
vector<int> g[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;

    q.push(start);

    dist[start] = 0;

    while (!q.empty()) {
        int curr {q.front()};

        q.pop();

        int curr_dist {dist[curr] + 1};

        for (int n : g[curr]) {
            if (curr_dist < dist[n]) {
                dist[n] = curr_dist;

                q.push(n);
            }
        }
    }
}

int main() {
    int start, end;

    cin >> n >> start >> end;

    for (int i {1}; i <= n; ++i) {
        dist[i] = INF;
    }

    for (int i {}; i < n - 1; ++i) {
        int x, y;

        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(start);

    cout << dist[end] << '\n';

    return 0;
}
