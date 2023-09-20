#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string a, b;

    cin >> n >> a >> m >> b;

    int p1 {}, ans {};

    while (p1 < (int) a.size() && p1 < (int) b.size() && a[p1] == b[p1]) {
        ++ans;
        ++p1;
    }

    cout << ans << '\n';

    return 0;
}
