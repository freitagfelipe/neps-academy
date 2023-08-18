#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

typedef pair<int, int> Point2D;

bitset<MAXN> bt;
vector<int> g[MAXN];

int dist(Point2D &a, Point2D &b) {
    int x_diff {a.first - b.first};
    int y_diff {a.second - b.second};

    return x_diff * x_diff + y_diff * y_diff;
}

void dfs(int u) {
    bt[u] = true;

    for (int to : g[u]) {
        if (!bt[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;

    cin >> n >> d;

    vector<Point2D> points(n);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            if (i == j) {
                continue;
            }

            if (dist(points[i], points[j]) <= d * d) {
                g[i].push_back(j);
            }
        }
    }

    int comp {};

    for (int i {}; i < n; ++i) {
        if (!bt[i]) {
            dfs(i);

            ++comp;
        }
    }

    if (comp == 1) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}
