#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5 + 10)

typedef long long ll;

int v[MAXN];
ll PSA[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int p1 {};

    for (int i {}; i < n; ++i) {
        int x, k;

        cin >> x >> k;

        for (int j {}; j < x; ++j) {
            v[p1++] = k;
        }
    }

    PSA[0] = v[0];

    for (int i {1}; i < p1; ++i) {
        PSA[i] = PSA[i - 1] + v[i];
    }

    int q;

    cin >> q;

    while (q--) {
        int l, r;

        cin >> l >> r;

        --l;
        --r;

        if (l == 0) {
            cout << PSA[r] << '\n';
        } else {
            cout << PSA[r] - PSA[l - 1] << '\n';
        }
    }

    return 0;
}