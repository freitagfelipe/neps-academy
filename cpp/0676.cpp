#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<ll> v(n);

    for (ll &x : v) {
        cin >> x;
    }

    cout << max(v[0] * v[1] * v[n - 1], v[n - 1] * v[n - 2] * v[n - 3]) << '\n';

    return 0;
}