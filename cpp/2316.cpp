#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, t;

    cin >> n >> r >> t;

    int ans {}, last {n};

    while (n < t) {
        n += last * r;

        last *= r;
    
        ++ans;
    }

    cout << ans << '\n';

    return 0;
}