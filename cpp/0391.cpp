#include <iostream>

using namespace std;

#define MAXN 1000

int v[MAXN];

int main() {
    int ans {}, n, m;

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    for (int i {}; i < n - 1; ++i) {
        int d {m - v[i]};

		v[i] += d;
		v[i + 1] += d;
		ans += abs(d);
    }

    cout << ans << '\n';

    return 0;
}
