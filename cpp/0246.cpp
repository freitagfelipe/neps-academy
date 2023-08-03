#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n), ord(n);
    vector<bool> b(n);

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        v[i] = ord[i] = x;
    }

    sort(ord.begin(), ord.end());

    int ans {};

    for (int i {}; i < n; ++i) {
        if (ord[i] != v[i]) {
            b[i] = true;

            ++ans;
        }
    }

    cout << ans << '\n';

    for (int i {}; i < n; ++i) {
        if (b[i]) {
            cout << ord[i] << " \n"[--ans == 0];
        }
    }

    return 0;
}