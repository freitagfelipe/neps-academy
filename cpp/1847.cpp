#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10
#define INF LONG_LONG_MAX

typedef long long ll;

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

    void update(int l, int r, T x) {
        this->update(1, 1, this->n, l, r, x);
    }

    T query(int l, int r) {
        Node result {this->query(1, 1, this->n, l, r)};

        return result.v == 0 ? result.ocurr : 0;
    }

private:
    struct Node {
        T lazy {};
        T v;
        int ocurr;

        Node(T v = INF, int ocurr = 1) {
            this->v = v;
            this->ocurr = ocurr;
        }

        Node operator+(const Node &other) {
            T min_v {min(this->v, other.v)};
            int ocurr {};

            if (min_v == this->v) {
                ocurr += this->ocurr;
            }

            if (min_v == other.v) {
                ocurr += other.ocurr;
            }

            return Node(min_v, ocurr);
        }
    };

    vector<int> arr;
    vector<Node> tree;
    int n;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];
            this->tree[node].v = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void lazy_propagation(int node, int l, int r) {
        if (this->tree[node].lazy == 0) {
            return;
        }

        this->tree[node].v += this->tree[node].lazy;

        if (l < r) {
            this->tree[node * 2].lazy += this->tree[node].lazy;
            this->tree[node * 2 + 1].lazy += this->tree[node].lazy;
        }

        this->tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int p, int q, T x) {
        this->lazy_propagation(node, l, r);

        if (q < l || r < p) {
            return;
        }

        if (p <= l && r <= q) {
            this->tree[node].lazy += x;

            this->lazy_propagation(node, l, r);

            return;
        }

        int mid {(l + r) / 2};

        this->update(node * 2, l, mid, p, q, x);
        this->update(node * 2 + 1, mid + 1, r, p, q, x);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    Node query(int node, int l, int r, int p, int q) {
        if (q < l || r < p) {
            return Node();
        }

        this->lazy_propagation(node, l, r);

        if (p <= l && r <= q) {
            return this->tree[node];
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

    SegmentTree<ll> st;

    st.build(n, v);

    for (int i {}; i < q; ++i) {
        int op, l, r;

        cin >> op >> l >> r;

        if (op == 1) {
            int x;

            cin >> x;

            st.update(l, r, x);
        } else {
            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}