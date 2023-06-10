#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        ++v[x];
    }

    int c {};

    for (int x : v) {
        cout << x << " \n"[++c == (int) v.size()];
    }

    return 0;
}