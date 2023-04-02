#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 3 * 100005

int v[MAXN];

class Node {
public: 
    Node(ll s = 0) {
        this->sum = s;
    }

    Node operator+(const Node &other) {
        return Node(this->sum + other.sum);
    }

private:
    ll sum;

    friend class SegmentTree;
};

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

    ll query(int l, int r) {
        return this->query(1, 1, this->n, l, r).sum;
    }

private:
    int n;
    vector<int> arr;
    vector<Node> tree;

    void build(int *v, int node, int l, int r) {
        if (l == r) {
            this->arr[l] = v[l - 1];

            this->tree[node].sum = v[l - 1];

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, node * 2, l, mid);
        this->build(v, node * 2 + 1, mid + 1, r);

        this->tree[node] = this->tree[node * 2] + this->tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int target_node, int v) {
        if (l == r) {
            this->arr[target_node] = v;

            this->tree[node].sum = v;

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
            return 0;
        } else if (l_target <= l && r <= r_target) {
            return tree[node].sum;
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

    SegmentTree st;

    st.build(n, v);

    for (int i {}; i < q; ++i) {
        int op;

        cin >> op;

        if (op == 1) {
            int t, v;

            cin >> t >> v;

            st.update(t, v);
        } else {
            int l, r;

            cin >> l >> r;

            cout << st.query(l, r) << '\n';
        }
    }
    
    return 0;
}