#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, k;

    cin >> n >> k;

    unordered_map<ll, int> freq;

    ll sum {}, ans {};
    freq[0] = 1;

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        sum += x;

        ans += freq[sum - k];

        ++freq[sum];
    }

    cout << ans << '\n';

    return 0;
}