#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10

int v[MAXN], prefix[MAXN], suffix[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    prefix[0] = v[0];
    suffix[n - 1] = v[n - 1];

    for (int i {1}; i < n; ++i) {
        prefix[i] = max(prefix[i - 1], v[i]);
    }

    for (int i {n - 1}; i >= 0; --i) {
        suffix[i] = max(suffix[i + 1], v[i]);
    }

    int ans {};

    for (int i {1}; i < n - 1; ++i) {
        if (prefix[i] > v[i] && v[i] < suffix[i]) {
            ++ans;
        }
    }
    
    cout << ans << '\n';

    return 0;
}