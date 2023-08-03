#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, k;

    cin >> n >> c >> k;

    vector<unordered_set<int>> p(n);

    for (int i {}; i < n; ++i) {
        for (int j {}; j < c; ++j) {
            int x;

            cin >> x;

            p[i].insert(x);
        }
    }

    bool someone_won {};
    int cnt {};

    for (int i {}; i < k; ++i) {
        int x;

        cin >> x;

        for (int j {}; j < n; ++j) {
            p[j].erase(x);

            if (p[j].size() == 0) {
                if (cnt++ > 0) {
                    cout << " ";
                }

                cout << j + 1;

                someone_won = true;
            }
        }

        if (someone_won) {
            break;
        }
    }

    cout << '\n';

    return 0;
}