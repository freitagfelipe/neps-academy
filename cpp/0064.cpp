#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100000

int v[MAXN];

int main() {
    int n, m, ans {};

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    sort(v, v + n);

    int p1 {}, p2 {n - 1};

    while (p1 <= p2) {
        if (v[p2] >= m || v[p1] + v[p2] > m) {
            ++ans;

            --p2;
        } else if (v[p1] + v[p2] <= m) {
            ++ans;

            ++p1;
            --p2;
        }
    }

    cout << ans << '\n';

    return 0;
}
