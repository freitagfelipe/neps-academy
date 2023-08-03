#include <bits/stdc++.h>

using namespace std;

#define MAXN 12000010

int solver(int n, int idx) {
    vector<bool> prime(n, true);

    int ans {}, i {2};

	for (; i * i <= n; ++i) {
        if (prime[i] && --idx == 0) {
            ans = i;

            break;
        }

		if (prime[i]) {
			for (int j {i * i}; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}

    for (; i <= n && idx != 0; ++i) {
        if (prime[i] && --idx == 0) {
            ans = i;

            break;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << solver(MAXN, n) << '\n';

    return 0;
}