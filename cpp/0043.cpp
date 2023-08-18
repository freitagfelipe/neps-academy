#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10

int n;
int BIT[MAXN];
int v[MAXN];

void update(int idx, int k) {
    int delta {k - v[idx]};

    v[idx] = k;

    for (; idx <= n; idx += idx & -idx) {
        BIT[idx] += delta;
    }
}

int query(int idx) {
    int ans {};

    for (; idx > 0; idx -= idx & -idx) {
        ans += BIT[idx];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    
    cin >> n >> q;

    for (int i {1}; i <= n; ++i) {
        int x;

        cin >> x;

        update(i, x);
    }

    while (q--) {
        int op;

        cin >> op;

        if (op == 0) {
            int idx, p;

            cin >> idx >> p;

            update(idx, p);
        } else {
            int idx;

            cin >> idx;

            cout << query(idx) << '\n';
        }
    }

    return 0;
}
