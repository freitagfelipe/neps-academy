#include <iostream>

using namespace std;

#define MAXN 10

int m[MAXN][MAXN];
int v[MAXN * 2 + 2];

int main() {
    int n;

    cin >> n;

    int k {};

    for (int i {}; i < n; ++i) {
        int row {};

        for (int j {}; j < n; ++j) {
            cin >> m[i][j];

            row += m[i][j];
        }

        v[k++] = row;
    }

    for (int i {}; i < n; ++i) {
        int column {};

        for (int j {}; j < n; ++j) {
            column += m[j][i];
        }

        v[k++] = column;
    }

    for (int i {}; i < n; ++i) {
        v[k] += m[i][i];
    }

    ++k;

    for (int i {}, j {n - 1}; i < n; ++i, --j) {
        v[k] += m[i][j];
    }

    for (int i {1}; i < n * 2 + 2; ++i) {
        if (v[i - 1] != v[i]) {
            cout << -1 << '\n';

            return 0;
        }
    }

    cout << v[0] << '\n';

    return 0;
}
