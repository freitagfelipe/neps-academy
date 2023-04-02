#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10
#define PINF int(1e9)
#define MINF -int(1e9)

int v[MAXN];

template <typename T>
class SegmentTree {
public:
    void build(int n, int *v) {
        this->n = n;

        arr.resize(n + 1);
        tree.resize(4 * n);

        this->build(v, 1, 1, n);
    }

    void update(int target_node, int v) {
        this->update(1, 1, this->n, target_node, v);
    }

    T query(int l, int r) {
        Node node {this->query(1, 1, this->n, l, r)};

        return node.max_v - node.min_v;
    }

private:
    struct Node {
        T max_v;
        T min_v;

        Node(T max_v = MINF, T min_v = PINF) {
            this->max_v = max_v;
            this->min_v = min_v;
        }

        Node operator+(const Node &other) {
            return Node(max(this->max_v, other.max_v), min(this->min_v, other.min_v));
        }
    };

    int n;
    vector<T> arr;
    vector<Node> tree;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];

            this->tree[node].max_v = v[l - 1];
            this->tree[node].min_v = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int target_node, int v) {
        if (l == r) {
            this->arr[target_node] += v;

            this->tree[node].max_v += v;
            this->tree[node].min_v += v;

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
            return tree[node];
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

    SegmentTree<int> st;

    st.build(n, v);

    for (int i {}; i < q; ++i) {
        int op;

        cin >> op;

        if (op == 1) {
            int id, x;

            cin >> id >> x;

            st.update(id, x); 
        } else {
            int l, r;

            cin >> l >> r;

            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}
