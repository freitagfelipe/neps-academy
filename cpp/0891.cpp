#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;

    vector<int> v {a, b, c};

    sort(v.begin(), v.end());

    int minv {v[0]}, midv {v[1]}, maxv {v[2]};

    int ans {3};

    if (maxv > midv) {
        if (midv > minv) {
            ans = 1;
        } else if (midv + minv < maxv) {
            ans = 1;
        } else {
            ans = 2;
        }
    } else if (midv > minv) {
        ans = 2;
    }

    cout << ans << '\n';

    return 0;
}