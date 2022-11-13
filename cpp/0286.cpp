#include <iostream>

using namespace std;

#define MAXN 100001

int p[MAXN], weight[MAXN], points[MAXN];

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

    if (weight[x] == p[y]) {
        p[x] = y;

        ++p[y];

        points[y] += points[x];
    } else if (weight[x] < weight[y]) {
        p[x] = y;

        points[y] += points[x];
    } else {
        p[y] = x;

        points[x] += points[y];
    }
}

int main() {
    int n, m;

    while (cin >> n >> m && n != 0) {
        for (int i {1}; i <= n; ++i) {
            p[i] = i;
            weight[i] = 0;

            cin >> points[i];
        }

        int answer {};

        for (int i {}; i < m; ++i) {
            int q, a, b;

            cin >> q >> a >> b;

            if (q == 1) {
                join(a, b);
            } else {
                int r_guild {find(1)}, a_guild {find(a)}, b_guild {find(b)};

                if (r_guild == a_guild && points[a_guild] > points[b_guild]) {
                    ++answer;
                } else if (r_guild == b_guild && points[a_guild] < points[b_guild]) {
                    ++answer;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}