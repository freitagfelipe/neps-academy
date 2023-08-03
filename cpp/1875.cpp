#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN int(1e2) + 10

int n;
ll BIT[MAXN][MAXN][MAXN];

void update(int idx, int idy, int idz, int k) {
    for (int x {idx}; x <= n; x += x & -x) {
        for (int y {idy}; y <= n; y += y & -y) {
            for (int z {idz}; z <= n; z += z & -z) {
                BIT[x][y][z] += k;
            }
        }
    }
}

ll query(int idx, int idy, int idz) {
    ll sum {};

    for (int x {idx}; x > 0; x -= x & -x) {
        for (int y {idy}; y > 0; y -= y & -y) {
            for (int z {idz}; z > 0; z -= z & -z) {
                sum += BIT[x][y][z];
            }
        }
    }

    return sum;
}

ll range_query(int xi, int yi, int zi, int xe, int ye, int ze) {
    ll sum {};

    sum += query(xe, ye, ze);
    sum -= query(xe, ye, zi - 1) + query(xe, yi - 1, ze) + query(xi - 1, ye, ze);
    sum += query(xe, yi - 1, zi - 1) + query(xi - 1, ye, zi - 1) + query(xi - 1, yi - 1, ze);
    sum -= query(xi - 1, yi - 1, zi - 1);

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> n >> q;

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y, z, k;

            cin >> x >> y >> z >> k;

            update(x, y, z, k);
        } else {
            int xi, yi, zi, xe, ye, ze;

            cin >> xi >> yi >> zi >> xe >> ye >> ze;

            cout << range_query(xi, yi, zi, xe, ye, ze) << '\n';
        }
    }

    return 0;
}