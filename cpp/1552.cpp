#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e6) + 10

typedef long long ll;
typedef __int128_t vll;

vll factorial[MAXN];
ll factorial_modular_inverse[MAXN];
ll modular_inverse[MAXN];

void build(int n, int m) {
	modular_inverse[0] = factorial[0] = factorial_modular_inverse[0] = 1;
	modular_inverse[1] = factorial[1] = factorial_modular_inverse[1] = 1;

	for (int i {2}; i <= n; ++i) {
		factorial[i] = (factorial[i - 1] * i) % m;

		modular_inverse[i] = (-m / i) * modular_inverse[m % i];
		modular_inverse[i] %= m;

		if (modular_inverse[i] < 0) {
			modular_inverse[i] += m;
		}

		factorial_modular_inverse[i] = (factorial_modular_inverse[i - 1] * modular_inverse[i]) % m;
	}
}

int query(int n, int k, int m) {
	return (factorial[n] * factorial_modular_inverse[k] * factorial_modular_inverse[n - k]) % m;
}

int main() {
    int n, k, m;

    cin >> n >> k >> m;

    if (k > n) {
        cout << 0 << '\n';

        return 0;
    }

    build(n, m);

    cout << query(n, k, m) << '\n';

    return 0;
}