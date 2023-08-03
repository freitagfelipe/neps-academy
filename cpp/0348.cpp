#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int BIT[MAXN][MAXN];

int query(int idx, int idy) {
    int ans {};

	for (int x {idx}; x > 0; x -= x & -x) {
		for (int y {idy}; y > 0; y -= y & -y) {
            ans = max(ans, BIT[x][y]);
		}
	}

    return ans;
}

void update(int idx, int idy, int k) {
	for (int x {idx}; x <= MAXN; x += x & -x) {
		for (int y {idy}; y <= MAXN; y += y & -y) {
            BIT[x][y] = max(BIT[x][y], k);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> q;

    while (q--) {
        int n;

        cin >> n;

        int ans {};

        for (int i {}; i < n; ++i) {
            int x, y;

            cin >> x >> y;

            int r {query(x, y) + 1};

            ans = max(ans, r);

            update(x, y, r);
        }

        cout << ans << '\n';

        memset(BIT, 0, sizeof(BIT));
    }

    return 0;
}