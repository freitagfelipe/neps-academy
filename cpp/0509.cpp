#include <iostream>

using namespace std;

#define MAXN int(1e3)
#define MAXM int(1e5)

int DP[MAXN + 1][MAXM + 1];
int m[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, n;

    cin >> v >> n;

    for (int i {1}; i <= n; ++i) {
        cin >> m[i];
    }

    for (int i {1}, dp_i {1}; i <= n; ++i, ++dp_i) {
        if (m[i] > v) {
            --dp_i;

            continue;
        }

        for (int j {}; j <= v; ++j) {
            if (m[i] > j) {
                DP[dp_i][j] = DP[dp_i - 1][j];
            } else {
                DP[dp_i][j] = max(DP[dp_i - 1][j], DP[dp_i - 1][j - m[i]] + m[i]);
            }

            if (DP[dp_i][j] == v) {
                cout << "S\n";

                return 0;
            }
        }
    }

    cout << "N\n";

    return 0;
}
