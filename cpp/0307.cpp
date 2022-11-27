#include <iostream>
#include <vector>

using namespace std;

#define MAXN 260
#define INF int(1e9)

int main() {
    int dp[MAXN][MAXN];
    int n, c;

    cin >> n >> c;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }

    for (int i {}; i < c; ++i) {
        int x, y, w;

        cin >> x >> y >> w;

        dp[x][y] = w;
        dp[y][x] = w;
    }

    for (int k {1}; k <= n; ++k) {
        for (int i {1}; i <= n; ++i) {
            for (int j {1}; j <= n; ++j) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    vector<int> solutions(n + 1, 0);

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            solutions[i] = max(solutions[i], dp[i][j]);
        }
    }

    int ans {solutions[1]};

    for (int i {2}; i <= n; ++i) {
        ans = min(ans, solutions[i]);
    }

    cout << ans << '\n';

    return 0;
}
