#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 510

struct Edge {
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator<(const Edge &edge) const {
        return this->w < edge.w;
    }
};

int n;
vector<Edge> edges;
int p[MAXN], w[MAXN];

int find(int x) {
    if (p[x] == x) {
        return x;
    }

    return p[x] = find(p[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (w[x] == w[y]) {
        p[x] = y;

        ++w[y];
    } else if (w[x] > w[y]) {
        p[y] = x;
    } else {
        p[x] = y;
    }
}

int kruskal() {
    for (int i {1}; i <= n; ++i) {
        p[i] = i;
    }

    sort(edges.begin(), edges.end());

    int mst_cost {};

    for (auto [u, v, w] : edges) {
        if (find(u) != find(v)) {
            join(u, v);

            mst_cost += w;
        }
    }

    return mst_cost;
}

int main() {
    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        edges.emplace_back(u, v, w);
    }

    cout << kruskal() << '\n';

    return 0;
}
