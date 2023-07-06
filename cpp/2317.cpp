#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int t;

    cin >> t;

    int ans {};

    while (t--) {
        int p;

        cin >> p;

        --p;

        if (v[p] > 0) {
            --v[p];

            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}