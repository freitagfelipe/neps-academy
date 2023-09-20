#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5 + 10)

int last_viwed[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(last_viwed, -1, sizeof(last_viwed));

    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int ans {}, p1 {}, p2 {};

    while (p1 < n && p2 < n) {
        int x {v[p2]};

        if (last_viwed[x] != -1 && last_viwed[x] >= p1) {
            p1 = last_viwed[x] > p1 ? last_viwed[x] + 1 : p1 + 1;

            while (p1 != last_viwed[v[p1]] && p1 < p2) {
                ++p1;
            }
        }

        last_viwed[x] = p2;

        ans = max(ans, p2++ - p1 + 1);
    }

    cout << ans << '\n';

    return 0;
}
