#include <bits/stdc++.h>

using namespace std;

#define MAXN 250010

int prefix[MAXN], suffix[MAXN], prefixm[MAXN], suffixm[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n + 1);

    for (int i {1}; i <= n; ++i) {
        cin >> v[i];
    }

    prefix[0] = v[1];
    prefixm[0] = v[1];

    for (int i {1}; i <= n; ++i) {
        prefix[i] = max(prefix[i - 1], v[i]);
        prefixm[i] = min(prefixm[i - 1], v[i]);
    }
    
    suffix[n + 1] = v[n];
    suffixm[n + 1] = v[n];

    for (int i {n}; i > 0; --i) {
        suffix[i] = max(suffix[i + 1], v[i]);
        suffixm[i] = min(suffixm[i + 1], v[i]);
    }

    for (int i {1}; i <= n; ++i) {
        int suffm {suffixm[i + 1]}, suff {suffix[i + 1]};
        int prefm {prefixm[i - 1]}, pref {prefix[i - 1]};

        cout << max({abs(suffm - v[i]), abs(suff - v[i]), abs(pref - v[i]), abs(prefm - v[i])}) << '\n';
    }

    return 0;
}