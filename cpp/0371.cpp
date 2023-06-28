#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10
#define INF INT_MAX

int v[MAXN];

template <typename T>
class SegmentTree {
public:
    void build(int n, int *v) {
        this->n = n;

        this->tree.resize(4 * n);

        this->build(v, 1, 1, n);
    }

    void update(int target_node, T v) {
        this->update(1, 1, this->n, target_node, v);
    }

    T query(int l, int r) {
        return this->query(1, 1, this->n, l, r).ans;
    }

private:
    struct Node {
        T ans;
        T minv;
        T maxv;

        Node(T minv = INF, T maxv = -INF, T ans = 0) {
            this->minv = minv;
            this->maxv = maxv;
            this->ans = ans;
        }

        Node operator+(const Node &other) {
            return Node(
                min(this->minv, other.minv),
                max(this->maxv, other.maxv),
                max({this->ans, other.ans, this->maxv - other.minv, other.maxv - this->minv})
            );
        }
    };

    int n;
    vector<Node> tree;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->tree[node].minv = this->tree[node].maxv = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int target_node, T v) {
        if (l == r) {
            this->tree[node].minv = min(this->tree[node].minv, v);
            this->tree[node].maxv = max(this->tree[node].maxv, v);

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

    cin >> n >> q;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    SegmentTree<long long int> st;

    st.build(n, v);

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int w, t;

            cin >> w >> t;

            st.update(t, w);
        } else {
            int l, r;

            cin >> l >> r;

            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}