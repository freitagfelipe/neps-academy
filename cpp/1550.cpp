#include <bits/stdc++.h>

using namespace std;

vector<int> get_prime_factor(int n) {
	vector<int> prime_factor;

	for (int i {2}; i * i <= n; ++i) {
		if (n % i != 0) {
			continue;
		}

		while (n % i == 0) {
		    prime_factor.push_back(i);

			n /= i;
		}
	}

    if (n > 1) {
        prime_factor.push_back(n);
    }

	return prime_factor;
}

int main() {
    int n;

    cin >> n;

    vector<int> prime_factor {get_prime_factor(n)};

    int i {1};

    cout << prime_factor.size() << '\n';

    for (int prime : prime_factor) {
        cout << prime << " \n"[i++ == prime_factor.size()];
    }

    return 0;
}