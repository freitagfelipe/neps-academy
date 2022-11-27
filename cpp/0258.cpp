#include <iostream>

using namespace std;

#define MAXN 110

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int mat[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n;

bool is_cell_valid(int i, int j, int value) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    } else if (visited[i][j]) {
        return false;
    } else if (mat[i][j] < value) {
        return false;
    }

    return true;
}

int dfs(int ri, int rj) {
    visited[ri][rj] = true;

    int ans {1};

    for (int i {}; i < 4; ++i) {
        int ni {ri + di[i]};
        int nj {rj + dj[i]};

        if (is_cell_valid(ni, nj, mat[ri][rj])) {
            visited[ni][nj] = true;

            ans += dfs(ni, nj);
        }
    }

    return ans;
}

int main() {
    int si, sj;

    cin >> n >> si >> sj;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << dfs(si - 1, sj - 1) << '\n';

    return 0;
}
