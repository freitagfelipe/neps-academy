#include <bits/stdc++.h>

using namespace std;

int main() {
    int sz;
    string a, b;
    int ans {};

    cin >> sz >> a >> b;

    for (int i {}; i < sz; ++i) {
        ans += a[i] == 'C' && b[i] == 'C';
    }

    cout << ans << '\n';

    return 0;
}