#include <bits/stdc++.h>

using namespace std;

#define MAXN 3 * int(1e5) + 10

typedef tuple<int, int, int> consult;

int n;
int BIT[MAXN];

void update(int idx, int k) {
    for (; idx <= n; idx += idx & -idx) {
        BIT[idx] += k;
    }
}

int query(int idx) {
    int ans {};

    for (; idx > 0; idx -= idx & -idx){
        ans += BIT[idx];
    }

    return ans;
}

int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> n >> q;

    vector<int> nums(n);
    vector<consult> queries(q);

    for (int &x : nums) {
        cin >> x;
    }

    for (int i {}; i < q; ++i) {
        auto &[r, l, idx] = queries[i];

        cin >> l >> r;

        idx = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> answers(q);
    vector<int> last_pos(MAXN, -1);
    int qc {};

    for (int i {1}; i <= n; ++i) {
        int k {nums[i - 1]};

        if (last_pos[k] != -1) {
            update(last_pos[k], -1);
        }

        last_pos[k] = i;

        update(i, 1);

        while (qc < q && get<0>(queries[qc]) == i) {
            auto [r, l, idx] = queries[qc++];

            answers[idx] = range_query(l, r);
        }
    }

    for (int ans : answers) {
        cout << ans << '\n';
    }

    return 0;
}