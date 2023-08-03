#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> g;

int get_max(int u) {
    if (u == 0) {
        return INT_MIN;
    }

    auto [f, s] = g[u];

    if (f == 0 && s == 0) {
        return u;
    }

    return max({get_max(f), get_max(s), u});
}

int get_min(int u) {
    if (u == 0) {
        return INT_MAX;
    }

    auto [f, s] = g[u];

    if (f == 0 && s == 0) {
        return u;
    }

    return min({get_min(f), get_min(s), u});
}

bool check(int u) {
    if (u == 0) {
        return true;
    }

    auto [f, s] = g[u];

    if (f == 0 && s == 0) {
        return true;
    }

    if ((f != 0 && get_max(f) >= u) || (s != 0 && get_min(s) <= u)) {
        return false;
    }

    return check(f) && check(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        g.assign(n + 1, pii());
        vector<bool> is_root(n + 1, true);

        is_root[0] = false;

        for (int i {1}; i <= n; ++i) {
            int l, r;

            cin >> l >> r;

            is_root[l] = is_root[r] = false;

            g[i].first = l;
            g[i].second = r;
        }

        int root {};

        for (int i {1}; i <= n; ++i) {
            if (is_root[i]) {
                root = i;

                break;
            }
        }

        cout << check(root) << '\n';
    }

    return 0;
}