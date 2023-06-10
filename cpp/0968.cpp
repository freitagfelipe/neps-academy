#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e4 + 10)

int n;
bool is_prime[MAXN];

void build() {
	for (int i {2}; i <= n; ++i) {
		is_prime[i] = true;
	}

	is_prime[0] = is_prime[1] = false;

	for (int i {2}; i * i <= n; ++i) {
		if (is_prime[i]) {
			for (int j {i * i}; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {
    cin >> n;

    build();

    for (int i {2}; i <= n; ++i) {
        if (is_prime[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}