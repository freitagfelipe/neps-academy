#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

typedef long long ll;

ll PSM[MAXN][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    for (int x {1}; x <= n; ++x) {
        for (int y {1}; y <= n; ++y) {
            for (int z {1}; z <= n; ++z) {
                int k;

                cin >> k;

                PSM[x][y][z] = PSM[x - 1][y][z] + PSM[x][y - 1][z] + PSM[x][y][z - 1];
                PSM[x][y][z] -= PSM[x - 1][y - 1][z] + PSM[x][y - 1][z - 1] + PSM[x - 1][y][z - 1];
                PSM[x][y][z] += PSM[x - 1][y - 1][z - 1] + k;
            }
        }
    }

    while (q--) {
        int xi, yi, zi, xe, ye, ze;

        cin >> xi >> yi >> zi >> xe >> ye >> ze;

        ll sum {};

        sum += PSM[xe][ye][ze];
        sum -= PSM[xi - 1][ye][ze] + PSM[xe][yi - 1][ze] + PSM[xe][ye][zi - 1];
        sum += PSM[xi - 1][yi - 1][ze] + PSM[xe][yi - 1][zi - 1] + PSM[xi - 1][ye][zi - 1];
        sum -= PSM[xi - 1][yi - 1][zi - 1];

        cout << sum << '\n';
    }

    return 0;
}