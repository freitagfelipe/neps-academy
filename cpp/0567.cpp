#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, m;
bitset<MAXN> visited[MAXN];
int mat[MAXN][MAXN];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool is_valid(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || mat[i][j] == 0) {
        return false;
    }

    return true;
}

void dfs(int i, int j) {
    visited[i][j] = true;

    for (int k {}; k < 4; ++k) {
        int ni {i + di[k]}, nj {j + dj[k]};

        if (is_valid(ni, nj)) {
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
            if (!visited[i][j] && mat[i][j] == 1) {
                ++comp;

                dfs(i, j);
            }
        }
    }
    
    cout << comp << '\n';

    return 0;
}
