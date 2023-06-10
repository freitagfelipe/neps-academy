#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e6) + 10

int v[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;

    cin >> n >> d;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    int p1 {}, p2 {}, sum {v[0]}, ans {};

    while (p1 < n && p2 < n) {
        ans = max(ans, p2 - p1 + 1);

        if (sum + v[p2 + 1] <= d) {
            if (++p2 < n) {
                sum += v[p2];
            }
        } else {
            sum -= v[p1++];
        }
    }

    cout << ans << '\n';

    return 0;
}