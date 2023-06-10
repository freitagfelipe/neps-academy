#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5 + 10)

int v[MAXN];

template <typename T>
class SegmentTree {
public:
    void build(int n, int *v) {
        this->n = n;

        this->arr.resize(n + 1);
        this->tree.resize(4 * n);

        this->build(v, 1, 1, n);
    }

    void update(int l, int r, T v) {
        this->update(1, 1, this->n, l, r, v);
    }

    T query(int l, int r) {
        return this->query(1, 1, this->n, l, r).count;
    }

private:
    struct Node {
        T count;
        T lazy;

        Node(T c = 0) {
            this->count = c;
            this->lazy = -1;
        }

        Node operator+(const Node &other) {
            return Node(this->count + other.count);
        }
    };

    int n;
    vector<T> arr;
    vector<Node> tree;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];

            this->tree[node].count = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void lazy_propagation(int node, int l, int r) {
        if (this->tree[node].lazy == -1) {
            return;
        }

        this->tree[node].count = (r - l + 1) * this->tree[node].lazy;

        if (l < r) {
            this->tree[node * 2].lazy = this->tree[node].lazy;
            this->tree[node * 2 + 1].lazy = this->tree[node].lazy;
        }

        this->tree[node].lazy = -1;
    }

    void update(int node, int l, int r, int p, int q, T v) {
        this->lazy_propagation(node, l, r);

        if (q < l || r < p) {
            return;
        }

        if (p <= l && r <= q) {
            this->tree[node].lazy = v;

            this->lazy_propagation(node, l, r);

            return;
        }

        int mid {(l + r) / 2};

        this->update(node * 2, l, mid, p, q, v);
        this->update(node * 2 + 1, mid + 1, r, p, q, v);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    Node query(int node, int l, int r, int p, int q) {
        if (q < l || r < p) {
            return Node();
        }

        this->lazy_propagation(node, l, r);
        
        if (p <= l && r <= q) {
            return tree[node];
        }

        int mid {(l + r) / 2};

        return this->query(node * 2, l, mid, p, q) + this->query(node * 2 + 1, mid + 1, r, p, q);
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
        int t;

        cin >> t;

        if (t == 1) {
            int l, r, k;

            cin >> l >> r >> k;

            st.update(l, r, k);
        } else {
            int l, r;

            cin >> l >> r;

            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}