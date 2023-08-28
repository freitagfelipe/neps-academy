#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, m;
int mat[MAXN][MAXN];
int di[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dj[] = {0, 0, 1, -1, -1, 1, 1, -1};
bitset<MAXN> bt[MAXN];

bool is_valid(int i, int j, int value) {
    if (i < 0 || j < 0 || i >= n || j >= m || bt[i][j]) {
        return false;
    } else if (abs(mat[i][j] - value) > 10 || mat[i][j] <= 128) {
        return false;
    }

    return true;
}

void dfs(int i, int j) {
    bt[i][j] = true;

    for (int k {}; k < 8; ++k) {
        int ni {i + di[k]}, nj {j + dj[k]};

        if (is_valid(ni, nj, mat[i][j])) {
            dfs(ni, nj);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    int comp {};

    for (int i {}; i < n; ++i) {
        for (int j {}; j < m; ++j) {
            if (!bt[i][j] && mat[i][j] > 128) {
                dfs(i, j);

                ++comp;
            }
        }
    }

    cout << comp << '\n';

    return 0;
}
