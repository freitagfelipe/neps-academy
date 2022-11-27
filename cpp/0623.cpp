#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 10

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int mat[MAXN + 2][MAXN + 2];
int dist[MAXN + 2][MAXN + 2];
int l, c;

bool is_cell_valid(int i, int j) {
    if (i < 0 || i >= l || j < 0 || j >= c) {
        return false;
    } else if (dist[i][j] != -1 || mat[i][j] == 2) {
        return false;
    }

    return true;
}

int bfs(int ri, int rj) {
    queue<pair<int, int>> q;

    q.push({ri, rj});

    dist[ri][rj] = 0;

    while (!q.empty()) {
        auto [ci, cj] = q.front();

        q.pop();

        int curr_dist {dist[ci][cj] + 1};

        for (int i {}; i < 4; ++i) {
            int ni {ci + di[i]};
            int nj {cj + dj[i]};

            if (!is_cell_valid(ni, nj)) {
                continue;
            }

            if (mat[ni][nj] == 0) {
                return curr_dist;
            }

            if (dist[ni][nj] == -1 || curr_dist < dist[ni][nj]) {
                q.push({ni, nj});

                dist[ni][nj] = curr_dist;
            }
        }
    }

    return -1;
}

int main() {
    memset(dist, -1, sizeof(dist));

    int si, sj;

    cin >> l >> c;

    for (int i {}; i < l; ++i) {
        for (int j {}; j < c; ++j) {
            cin >> mat[i][j];

            if (mat[i][j] == 3) {
                si = i;
                sj = j;
            }
        }
    }

    cout << bfs(si, sj) << '\n';

    return 0;
}
