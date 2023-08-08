#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, p;

    cin >> n >> p;

    set<int> s;

    for (int i {1}; i <= n; ++i) {
        s.insert(i);
    }

    int ans {};

    for (int i {}; i < p; ++i) {
        int x;

        cin >> x;

        auto it {s.upper_bound(x)};

        if (it == s.begin()) {
            break;
        } else {
            ++ans;

            --it;

            s.erase(it);
        }
    }

    cout << ans << '\n';

    return 0;
}