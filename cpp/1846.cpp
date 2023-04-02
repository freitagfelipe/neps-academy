#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e5) + 10
#define MIN_INF LONG_LONG_MIN

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

    void update(int target_node, T v) {
        this->update(1, 1, this->n, target_node, v);
    }

    T query(int l, int r) {
        return this->query(1, 1, this->n, l, r).max_sum;
    }

private:
    struct Node {
        T left {};
        T right {};
        T sum {};
        T max_sum;

        Node(T max_sum = MIN_INF) {
            this->max_sum = max_sum;
        }

        Node operator+(const Node &other) {
            Node result;

            result.sum = this->sum + other.sum;
            result.left = max(this->left, this->sum + other.left);
            result.right = max(other.right, this->right + other.sum);
            result.max_sum = max({this->max_sum, other.max_sum, this->right + other.left});

            return result;
        }
    };

    int n;
    vector<T> arr;
    vector<Node> tree;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];

            this->tree[node].max_sum = max(0, v[l - 1]);
            this->tree[node].sum = v[l - 1];
            this->tree[node].left = v[l - 1];
            this->tree[node].right = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int target_node, T v) {
        if (l == r) {
            this->arr[target_node] += v;

            this->tree[node].max_sum = max<T>(0, this->arr[target_node]);
            this->tree[node].sum += v;
            this->tree[node].right += v;
            this->tree[node].left += v;

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

    SegmentTree<long long> st;

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