#include <bits/stdc++.h>

using namespace std;

int main() {
    int v[10];
    int n;

    for (int &x : v) {
        cin >> x;
    }

    cin >> n;

    vector<int> ans;

    for (int i {}; i < 10; ++i) {
        if (v[i] == n) {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0) {
        cout << "Mia x\n";

        return 0;
    }

    cout << ans.size() << '\n';

    size_t c {};

    for (int x : ans) {
        cout << x << " \n"[++c == ans.size()];
    }

    return 0;
}