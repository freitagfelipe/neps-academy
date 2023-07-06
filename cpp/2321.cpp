#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(3);

    for (int &x : v) {
        cin >> x;
    }

    sort(v.rbegin(), v.rend());

    int ans {};

    while (n >= v.back() && v.size() > 0) {
        n -= v.back();

        v.pop_back();

        ++ans;
    }

    cout << ans << '\n';

    return 0;
}