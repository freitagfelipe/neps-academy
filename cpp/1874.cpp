#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN int(1e3) + 10

int n;
int mat[MAXN][MAXN];
ll BIT[MAXN][MAXN];

void update(int idx, int idy, int k) {
    int delta {k - mat[idx][idy]};

    for (int x {idx}; x <= n; x += x & -x) {
        for (int y {idy}; y <= n; y += y & -y) {
            BIT[x][y] += delta;
        }
    }

    mat[idx][idy] = k;
}

ll query(int idx, int idy) {
    ll sum {};

    for (int x {idx}; x > 0; x -= x & -x) {
        for (int y {idy}; y > 0; y -= y & -y) {
            sum += BIT[x][y];
        }
    }

    return sum;
}

ll range_query(int xi, int yi, int xe, int ye) {
    return query(xe, ye) - query(xe, yi - 1) - query(xi - 1, ye) + query(xi - 1, yi - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> n >> q;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            int x;

            cin >> x;

            update(i, j, x);
        }
    }

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y, k;

            cin >> x >> y >> k;

            update(x, y, k);
        } else {
            int xi, yi, xe, ye;

            cin >> xi >> yi >> xe >> ye;

            cout << range_query(xi, yi, xe, ye) << '\n';
        }
    }

    return 0;
}