#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10

int v[MAXN];

template <typename T, typename U>
class SegmentTree {
public:
    void build(int n, U *v) {
        this->n = n;

        this->arr.resize(n + 1);
        this->tree.resize(n * 4);

        this->build(v, 1, 1, n);
    }

    void update(int target_node, U v) {
        this->update(1, 1, this->n, target_node, v);
    }

    T query(int l, int r) {
        return this->query(1, 1, this->n, l, r).ans;
    }
private:
    struct Node {
        int ans;

        Node(int ans = 1) {
            this->ans = ans;
        }

        Node operator+(const Node &o) {
            return Node(this->ans * o.ans);
        }
    };

    int n;
    vector<U> arr;
    vector<Node> tree;

    void build(U *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];
            this->tree[node] = v[l - 1] < 0 ? -1 : v[l - 1] > 0 ? 1 : 0;

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int target_node, U v) {
        if (l == r) {
            this->tree[node] = v < 0 ? -1 : v > 0 ? 1 : 0;
            this->arr[l] = v;

            return;
        }

        int mid {(l + r) / 2};

        if (target_node <= mid) {
            this->update(node * 2, l, mid, target_node, v);
        } else {
            this->update(node * 2 + 1, mid + 1, r, target_node, v);
        }

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    Node query(int node, int l, int r, int l_target, int r_target) {
        if (r_target < l || r < l_target) {
            return Node();
        } else if (l_target <= l && r <= r_target) {
            return this->tree[node];
        }

        int mid {(l + r) / 2};

        return this->query(node * 2, l, mid, l_target, r_target) + this->query(node * 2 + 1, mid + 1, r, l_target, r_target);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    while (cin >> n >> q) {
        for (int i {}; i < n; ++i) {
            cin >> v[i];
        }

        SegmentTree<int, int> st;

        st.build(n, v);

        while (q--) {
            char op;

            cin >> op;

            if (op == 'C') {
                int t, v;

                cin >> t >> v;

                st.update(t, v);
            } else if (op == 'P') {
                int l, r;

                cin >> l >> r;

                int res {st.query(l, r)};

                cout << (res == 0 ? '0' : res < 0 ? '-' : '+');
            }
        }

        cout << '\n';
    }

    return 0;
}