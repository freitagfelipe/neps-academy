#include <bits/stdc++.h>

using namespace std;

#define MAXN 3 * int(1e5) + 10

struct Data {
    int val;
    int l;
    int r;
    int idx;

    Data(int val, int l, int r, int idx) {
        this->val = val;
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    bool operator<(const Data &t) const {
        if (this->val == t.val) {
            return this->l > t.l;
        }

        return this->val > t.val;
    }
};

int n;
int BIT[MAXN];

void update(int idx, int k) {
    for (; idx <= n; idx += idx & -idx) {
        BIT[idx] += k;
    }
}

int query(int idx) {
    int ans {};

    for (; idx > 0; idx -= idx & -idx) {
        ans += BIT[idx];
    }

    return ans;
}

int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int q;

    cin >> n >> q;

    vector<Data> data;

    for (int i {1}; i <= n; ++i) {
        int x;

        cin >> x;

        data.emplace_back(x, -1, -1, i);
    }

    for (int i {}; i < q; ++i) {
        int val, l, r;

        cin >> l >> r >> val;

        data.emplace_back(val, l, r, i);
    }

    sort(data.begin(), data.end());

    vector<int> answers(q);

    for (const Data &d : data) {
        if (d.l == -1) {
            update(d.idx, 1);
        } else {
            answers[d.idx] = range_query(d.l, d.r);
        }
    }

    for (int ans : answers) {
        cout << ans << '\n';
    }

    return 0;
}