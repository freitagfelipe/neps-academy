#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define L(x) (x << 1)
#define R(x) (L(x) | 1)
#define MAXN int(1e5) + 10

int v[MAXN];

template <typename T, typename U>
class SegmentTree {
public:
    void build(int n, U *v) {
        this->n = n;

        this->tree.resize(n * 4);

        this->build(v, 1, 1, n);
    }

    pair<int, T> query(int l, int r) {
        Node res {this->query(1, 1, this->n, l, r)};
        
        return {res.max_c, res.max_sum};
    }

private:
    struct Node {
        T prefix;
        T suffix;
        T max_sum;
        T sum;
        int prefix_c;
        int suffix_c;
        int sum_c;
        int max_c;

        Node() = default;

        Node(U initialize) {
            this->prefix = initialize;
            this->suffix = initialize;
            this->sum = initialize;
            this->max_sum = initialize;
            this->prefix_c = 1;
            this->suffix_c = 1;
            this->sum_c = 1;
            this->max_c = 1;
        }

        Node operator+(const Node &o) {
            Node node;

            node.sum = this->sum + o.sum;
            node.sum_c = this->sum_c + o.sum_c;

            node.prefix = max(this->prefix, this->sum + o.prefix);

            if (this->prefix > this->sum + o.prefix) {
                node.prefix_c = this->prefix_c;
            } else {
                node.prefix_c = this->sum_c + o.prefix_c;
            }

            node.suffix = max(this->suffix + o.sum, o.suffix);

            if (o.suffix > this->suffix + o.sum) {
                node.suffix_c = o.suffix_c;
            } else {
                node.suffix_c = this->suffix_c + o.sum_c;
            }

            node.max_sum = max({this->max_sum, o.max_sum, this->suffix + o.prefix});

            if (this->max_sum > o.max_sum && this->max_sum > this->suffix + o.prefix) {
                node.max_c = this->max_c;
            } else if (o.max_sum > this->max_sum && o.max_sum > this->suffix + o.prefix) {
                node.max_c = o.max_c;
            } else {
                node.max_c = this->suffix_c + o.prefix_c;
            }

            return node;
        }
    };

    int n;
    vector<Node> tree;

    void build(U *v, int node, int l, int r) {
        if (l == r) {
            this->tree[node] = Node(v[l - 1]);

            return;
        }

        int mid {(l + r) / 2};

        this->build(v, L(node), l, mid);
        this->build(v, R(node), mid + 1, r);

        this->tree[node] = this->tree[L(node)] + this->tree[R(node)];
    }

    Node query(int node, int l, int r, int l_target, int r_target) {
		if (l == l_target && r == r_target) {
			return this->tree[node];
		}

		int mid {(l + r) / 2};

		if (r_target <= mid) {
			return this->query(L(node), l, mid, l_target, r_target);
		}

		if (l_target > mid) {
			return this->query(R(node), mid + 1, r, l_target, r_target);
		}

        return this->query(L(node), l, mid, l_target, mid) + this->query(R(node), mid + 1, r, mid + 1, r_target);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        for (int i {}; i < n; ++i) {
            cin >> v[i];
        }

        SegmentTree<ll, int> st;

        st.build(n, v);

        int q;

        cin >> q;

        while (q--) {
            int l, r;

            cin >> l >> r;

            auto [c, sum] = st.query(l, r);

            cout << sum << " " << c << '\n';
        }
    }

    return 0;
}