#include <iostream>

using namespace std;

#define MAXN 100000

int nums_up[MAXN + 1], nums_down[MAXN + 1], psa[MAXN + 2];

int main() {
    int n, t;

    cin >> n >> t;

    for (int i {}; i < n; ++i) {
        cin >> nums_up[i];
    }

    for (int i {}; i < n; ++i) {
        cin >> nums_down[i];
    }

    for (int i {}; i < t; ++i) {
        int a, b;

        cin >> a >> b;

        ++psa[a];
        --psa[b + 1];
    }

    for (int i {1}; i <= n; ++i) {
        psa[i] += psa[i - 1];
    }

    int count {};

    for (int i {0}; i < n; ++i) {
        if (count++ > 0) {
            cout << " ";
        }

        if (!(psa[i + 1] & 1)) {
            cout << nums_up[i];
        } else {
            cout << nums_down[i];
        }
    }

    cout << '\n';

    return 0;
}
