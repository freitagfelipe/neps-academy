#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sz, q;
    string s;

    cin >> sz >> s >> q;

    vector<unordered_map<char, int>> aux(sz);

    while (q--) {
        string qs;

        cin >> qs;

        for (int i {}; i < sz; ++i) {
            if (s[i] != qs[i]) {
                ++aux[i][qs[i]];
            }
        }
    }

    int ans {};

    for (int i {}; i < sz; ++i) {
        int max_c {};

        for (auto [_, occurr] : aux[i]) {
            max_c = max(max_c, occurr);
        }

        ans += max_c;
    }

    cout << ans << '\n';

    return 0;
}