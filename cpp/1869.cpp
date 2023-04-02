#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) * 3 + 10

int n;
int BIT[MAXN];

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        BIT[idx] ^= val;
    }
}

void range_update(int l, int r, int val) {
    update(l, val);
    update(r + 1, val);
}

int point_query(int idx) {
    int ans {};

    for (; idx > 0; idx -= idx & -idx) {
        ans ^= BIT[idx];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> n >> q;

    for (int i {1}; i <= n; ++i) {
        int aux;

        cin >> aux;

        range_update(i, i, aux);
    }

    for (int i {}; i < q; ++i) {
        int op, l, r;

        cin >> op;

        if (op == 1) {
            int l, r, x;

            cin >> l >> r >>x;

            range_update(l, r, x);
        } else {
            int pq;

            cin >> pq;

            cout << point_query(pq) << '\n';
        }
    }

    return 0;
}