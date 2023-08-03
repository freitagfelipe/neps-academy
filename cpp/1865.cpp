#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN int(1e5) + 10

pair<int, pii> g[MAXN];

bool is_left_child(int node) {
    return g[g[node].first].second.first == node;
}

void left_rotation(int node) {
    int x {g[node].second.second};
    int beta {g[x].second.first};

    g[node].second.second = beta;

    if (beta != 0) {
        g[beta].first = node;
    }

    g[x].first = g[node].first;

    if (g[node].first != 0) {
        if (is_left_child(node)) {
            g[g[node].first].second.first = x;
        } else {
            g[g[node].first].second.second = x;
        }
    }

    g[x].second.first = node;
    g[node].first = x;
}

void right_rotation(int node) {
    int x {g[node].second.first};
    int beta {g[x].second.second};

    g[node].second.first = beta;

    if (beta != 0) {
        g[beta].first = node;
    }

    g[x].first = g[node].first;

    if (g[node].first != 0) {
        if (is_left_child(node)) {
            g[g[node].first].second.first = x;
        } else {
            g[g[node].first].second.second = x;
        }
    }

    g[x].second.second = node;
    g[node].first = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    for (int i {1}; i <= n; ++i) {
        int l, r;

        cin >> l >> r;


        g[l].first = i;
        g[r].first = i;
        g[i].second.first = l;
        g[i].second.second = r;
    }

    while (q--) {
        char op;
        int t;

        cin >> op >> t;

        if (op == 'L') {
            left_rotation(t);
        } else {
            right_rotation(t);
        }
    }

    for (int i {1}; i <= n; ++i) {
        cout << g[i].second.first << " " << g[i].second.second << "\n";
    }

    return 0;
}