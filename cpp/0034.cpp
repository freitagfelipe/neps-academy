#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1010

int v[MAXN];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        v[i] = -x;
    }

    sort(v, v + n);

    int ans {}, lim {v[k - 1]};

    for (int i {}; i < n; ++i) {
        if (v[i] <= lim) {
            ++ans;
        } else {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
