#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);

    for (int &x : v) {
        int q, s;

        cin >> q >> s;

        x = q % s;
    }

    sort(v.begin(), v.end());

    cout << v[k - 1] << '\n';

    return 0;
}
