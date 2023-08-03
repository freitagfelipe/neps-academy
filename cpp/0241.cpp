#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n + 2);

    for (int i {1}; i <= n; ++i) {
        cin >> v[i];
    }

    for (int i {1}; i <= n; ++i) {
        cout << v[i - 1] + v[i + 1] + v[i] << '\n';
    }

    return 0;
}