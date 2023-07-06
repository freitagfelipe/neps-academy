#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define INF int(1e6)

typedef tuple<int, int, int> tii;

int n;
int mat[MAXN][MAXN];
int dist[MAXN][MAXN];
bitset<MAXN> visited[MAXN];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool is_valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    } else if (visited[i][j]) {
        return false;
    }

    return true;
}

void dijkstra(int si, int sj) {
    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            dist[i][j] = INF;
        }
    }

    dist[si][sj] = 0;

    priority_queue<tii, vector<tii>, greater<tii>> pq;

    pq.push({0, si, sj});

    while (!pq.empty()) {
        auto [_, ci, cj] = pq.top();

        pq.pop();

        if (visited[ci][cj]) {
            continue;
        }

        visited[ci][cj] = true;

        for (int k {}; k < 4; ++k) {
            int ni {ci + di[k]}, nj {cj + dj[k]};

            if (is_valid(ni, nj) && dist[ci][cj] + mat[ni][nj] < dist[ni][nj]) {
                dist[ni][nj] = dist[ci][cj] + mat[ni][nj];

                pq.push({dist[ni][nj], ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    dijkstra(0, 0);

    cout << dist[n - 1][n - 1] << '\n';

    return 0;
}