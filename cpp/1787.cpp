#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int p1 {}, p2 {}, ans {1};

    while (p1 < n && p2 < n) {
        if (p2 + 1 < n && v[p2] <= v[p2 + 1]) {
            ans = max(ans, p2 + 1 - p1 + 1);
        } else {
            p1 = p2 + 1;
        }

        ++p2;
    }

    cout << ans << '\n';

    return 0;
}