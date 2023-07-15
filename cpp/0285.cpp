#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10

int n;
vector<int> BIT;

void update(int idx, int k) {
    for (; idx <= n; idx += idx & -idx) {
        BIT[idx] += k;
    }
}

int query(int idx) {
    int sum {};

    for (; idx > 0; idx -= idx & -idx) {
        sum += BIT[idx];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n != 0) {
        vector<int> v(n);

        BIT.assign(n + 1, 0);

        for (int &x : v) {
            cin >> x;
        }

        int inv {};

        for (int i {(int) v.size() - 1}; i >= 0; --i) {
            inv += query(v[i] - 1);

            update(v[i], 1);
        }

        if (inv % 2 == 0) {
            cout << "Carlos\n";
        } else {
            cout << "Marcelo\n";
        }
    }

    return 0;
}