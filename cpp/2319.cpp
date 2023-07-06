#include <bits/stdc++.h>

using namespace std;

#define MAXN 510

int mat[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }

    int t;

    cin >> t;

    int ans {};

    while (t--) {
        int i, j;

        cin >> i >> j;

        if (mat[i][j] > 0) {
            --mat[i][j];

            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}