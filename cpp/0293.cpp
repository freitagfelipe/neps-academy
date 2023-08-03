#include <bits/stdc++.h>

using namespace std;

#define MAXN 12000010

unordered_map<int, int> solver(int n) {
    vector<bool> prime(n, true);
    unordered_map<int, int> ans;

    int i {2}, p {1};

	for (; i * i <= n; ++i) {
		if (prime[i]) {
            ans[i] = p++;

			for (int j {i * i}; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}

    for (; i <= n; ++i) {
        if (prime[i]) {
            ans[i] = p++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map primes {solver(MAXN)};
    int q;

    cin >> q;

    while (q--) {
        int k;

        cin >> k;

        cout << primes[k] << '\n';
    }

    return 0;
}