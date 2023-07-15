#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll norm(const pll &a) {
    auto [x, y] = a;

	return x * x + y * y;
}

ll count(vector<ll> &v, int start, int end) {
	ll ans {};
    vector<ll> result;

    int p1 {start}, mid {(start + end) / 2}, p2 {mid + 1};

    while (p1 <= mid && p2 <= end) {
        if (v[p1] <= v[p2]) {
            result.push_back(v[p1++]);
        } else {
			ans += mid - p1 + 1;

            result.push_back(v[p2++]);
        }
    }

    while (p1 <= mid) {
        result.push_back(v[p1++]);
    }

    while (p2 <= end) {
        result.push_back(v[p2++]);
    }

    copy(result.begin(), result.end(), v.begin() + start);

	return ans;
}

ll inversions_count(vector<ll> &v, int start, int end) {
    ll ans {};
    
    if (end > start) {
        int mid {(start + end) / 2};

        ans += inversions_count(v, start, mid);
        ans += inversions_count(v, mid + 1, end);

        ans += count(v, start, end);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin >> n;

    vector<ll> v;

    for (int i {}; i < n; ++i) {
        int x, y;

        cin >> x >> y;

        v.push_back(norm({x, y}));
    }

    cout << (n * (n - 1) / 2) - inversions_count(v, 0, n - 1) << '\n';

    return 0;
}