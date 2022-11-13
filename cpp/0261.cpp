#include <iostream>

using namespace std;

#define MAXN 100000

int v[MAXN], p[MAXN + 1];

int binary_search(int x, int n) {
    int start {}, end {n - 1}, i {};

    while (start <= end) {
        int mid {(start + end) / 2};

        if (x == v[mid]) {
            i = mid + 1;

            break;
        } else if (x < v[mid]) {
            i = mid;

            end = mid - 1;
        } else if (x > v[mid]) {
            i = mid + 1;

            start = mid + 1;
        }
    }

    return p[i];
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i {}; i < n - 1; ++i) {
        cin >> v[i];
    }

    for (int i {}; i < n; ++i) {
        cin >> p[i];
    }

    int count {};

    for (int i {}; i < m; ++i) {
        int x;

        cin >> x;

        if (count++ > 0) {
            cout << " ";
        }

        cout << binary_search(x, n - 1);
    }

    cout << '\n';

    return 0;
}