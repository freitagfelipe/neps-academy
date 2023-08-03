#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, c;
vector<pair<int, pii>> g;

void print_inorder(int u) {
    if (u == 0) {
        return;
    }

    auto [f, s] = g[u].second;

    print_inorder(f);

    cout << g[u].first << " \n"[++c == n];

    print_inorder(s);
}

void print_preorder(int u) {
    if (u == 0) {
        return;
    }

    cout << g[u].first << " \n"[++c == n];

    auto [f, s] = g[u].second;

    print_preorder(f);
    print_preorder(s);
}

void print_postorder(int u) {
    if (u == 0) {
        return;
    }

    auto [f, s] = g[u].second;

    print_postorder(f);
    print_postorder(s);

    cout << g[u].first << " \n"[++c == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    g.assign(n + 1, pair<int, pii>());
    vector<bool> is_root(n + 1, true);

    is_root[0] = false;

    for (int i {1}; i <= n; ++i) {
        cin >> g[i].first;
    }

    for (int i {1}; i <= n; ++i) {
        int l, r;

        cin >> l >> r;

        g[i].second = {l, r};
    
        is_root[l] = is_root[r] = false;
    }

    int root {};

    for (int i {1}; i <= n; ++i) {
        if (is_root[i]) {
            root = i;

            break;
        }
    }

    print_inorder(root);

    c = 0;

    print_preorder(root);

    c = 0;

    print_postorder(root);

    return 0;
}