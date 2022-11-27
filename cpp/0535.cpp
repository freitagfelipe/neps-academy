#include <iostream>
#include <queue>

using namespace std;

#define MAXN 201

int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, -1, 1, -1, 1};
int mat[MAXN][MAXN];
int l, c;

bool is_cell_valid(int i, int j) {
    if (i < 0 || i >= l || j < 0 || j >= c) {
        return false;
    } else if (mat[i][j] == 1) {
        return false;
    } else if (mat[i][j] == -1) {
        return false;
    }

    return true;
}

int bfs(int ri, int rj) {
    queue<pair<int, int>> q;

    q.push({ri, rj});

    mat[ri][rj] = 1;

    int ans {};

    while (!q.empty()) {
        auto [ci, cj] = q.front();

        q.pop();

        ++ans;

        for (int i {}; i < 8; ++i) {
            int ni {ci + di[i]};
            int nj {cj + dj[i]};

            if (is_cell_valid(ni, nj)) {
                q.push({ni, nj});

                mat[ni][nj] = 1;
            }
        }
    }

    return ans;
}

int main() {
    int si, sj, k;

    cin >> l >> c >> si >> sj >> k;

    for (int i {}; i < k; ++i) {
        int y, x;

        cin >> y >> x;

        mat[y - 1][x - 1] = -1;
    }

    cout << bfs(si - 1, sj - 1) << '\n';

    return 0;
}
