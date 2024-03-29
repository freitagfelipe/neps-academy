#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count(vector<int> &v, int start, int end) {
	ll ans {};
    vector<int> result;

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

ll inversions_count(vector<int> &v, int start, int end) {
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

    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    cout << inversions_count(v, 0, n - 1) << '\n';

    return 0;
}