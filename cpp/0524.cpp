#include <iostream>

using namespace std;

#define MAXN 100001

int h[MAXN];

int main() {
    int n, k;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> h[i];
    }

    cin >> k;

    int i {}, j {n - 1};

    while (i <= j) {
        if (h[i] + h[j] == k) {
            break;
        } else if (h[i] + h[j] > k) {
            --j;
        } else {
            ++i;
        }
    }

    cout << h[i] << " " << h[j] << '\n';

    return 0;
}
