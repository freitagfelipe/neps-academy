#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100000

int psa[10][MAXN + 1];
int total[10];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i {1}; i <= n; ++i) {
        int a;

        cin >> a;

        ++psa[a][i];

        for (int j {}; j < 10; ++j) {
            psa[j][i] += psa[j][i - 1];
        }
    }

    int l {};

    for (int i {}; i < m; ++i) {
        int c;

        cin >> c;

        for (int j {}; j < 10; ++j) {
            if (c > l) {
                total[j] += psa[j][c] - psa[j][l];
            } else {
                total[j] += psa[j][l - 1] - psa[j][c - 1];
            }
        }

        l = c;
    }

    int count {};

    for (int num : total) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << num;
    }

    cout << '\n';

    return 0;
}
