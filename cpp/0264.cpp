#include <iostream>

using namespace std;

#define MAXN 100001

int p[MAXN], weight[MAXN];

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

    if (weight[x] == weight[y]) {
        p[x] = y;

        ++weight[y];
    } else if (weight[x] > weight[y]) {
        p[y] = x;
    } else {
        p[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    for (int i {1}; i <= n; ++i) {
        p[i] = i;
    }

    for (int i {}; i < k; ++i) {
        char c;
        int a, b;

        cin >> c >> a >> b;

        if (c == 'C') {
            if (find(a) == find(b)) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
        } else {
            join(a, b);
        }
    }

    return 0;
}