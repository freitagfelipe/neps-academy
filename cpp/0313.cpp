#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int DP[MAXN];

bool can_make(int k, const vector<int> &coins) {
    if (k == 0) {
        return true;
    }

    if (k < 0) {
        return false;
    }

    if (DP[k] >= 0) {
        return DP[k];
    }

    for (int coin : coins) {
        if (can_make(k - coin, coins)) {
            return (DP[k - coin] = 1);
        }
    }

    return (DP[k] = 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(DP, -1, sizeof(DP));

    int n, k;

    cin >> n >> k;

    vector<int> coins(n);

    for (int &x : coins) {
        cin >> x;
    }

    int ans {};

    for (int i {1}; i < k; ++i) {
        if (DP[i] == 0) {
            ++ans;
        } else if (DP[i] == -1 && !can_make(i, coins)) {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}