#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
#define MAXP 1010

int M[MAXN][MAXN];
int P[MAXP];

int main() {
    int v, e;

    cin >> v >> e;

    for (int i {}; i < e; ++i) {
        int v, u;

        cin >> v >> u;

        M[v][u] = 1;
        M[u][v] = 1;
    }

    int q;

    cin >> q;

    int ans {q};

    while (q--) {
        int p;

        cin >> p;

        for (int i {}; i < p; ++i) {
            cin >> P[i];
        }

        for (int i {1}; i < p; ++i) {
            if (M[P[i - 1]][P[i]] == 0) {
                --ans;

                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}