#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, m;
	
	cin >> n >> m;

	ll ans {}, last {};

	for(int i {}; i < n; ++i) {
		int a;

		cin >> a;

		int x {max(a, m - a)}, y {min(a, m - a)};
		
		if (y >= last) {
			ans += y;
		
			last = y;
		} else if(x >= last) {
			ans += x;

			last = x;
		} else {
			ans = -1;

			break;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}