#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    v.push_back(0);

    sort(v.begin(), v.end());

    for (int i {}; i < (int) v.size() - 1; ++i) {
        if (v[i + 1] - v[i] > 8) {
            cout << "N\n";

            return 0;
        }
    }

    cout << "S\n";

    return 0;
}
