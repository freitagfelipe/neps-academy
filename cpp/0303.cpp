#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define INF int(1e9)

int main() {
    int DP[MAXN][MAXN];

    int n, m;

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            if (i == j) {
                DP[i][j] = 0;
            } else {
                DP[i][j] = INF;
            }
        }
    }

    for (int i {}; i < m; ++i) {
        int v, u, w;

        cin >> v >> u >> w;

        DP[v][u] = w;
        DP[u][v] = w;
    }

    for (int k {}; k < n; ++k) {
        for (int i {}; i < n; ++i) {
            for (int j {}; j < n; ++j) {
                if (DP[i][k] + DP[k][j] < DP[i][j]) {
                    DP[i][j] = DP[i][k] + DP[k][j];
                }
            }
        }
    }

    vector<int> solutions(n, 0);

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            solutions[i] = max(solutions[i], DP[i][j]);
        }
    }

    int ans {solutions[0]};

    for (int i {1}; i < n; ++i) {
        ans = min(ans, solutions[i]);
    }

    cout << ans << '\n';

    return 0;
}