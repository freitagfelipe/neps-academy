#include <bits/stdc++.h>

using namespace std;

int count(int start, int end, vector<int> &v) {
    int count {};
    vector<int> result;

    int p1 {start}, mid {(start + end) / 2}, p2 {mid + 1};

    while (p1 <= mid && p2 <= end) {
        if (v[p1] <= v[p2]) {
            result.push_back(v[p1++]);
        } else {
            count += mid - p1 + 1;
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

    return count;
}

int inversion_count(int start, int end, vector<int> &v) {
    int ans {};

    if (start < end) {
        int mid {(start + end) / 2};

        ans += inversion_count(start, mid, v);
        ans += inversion_count(mid + 1, end, v);
        ans += count(start, end, v);
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

    cout << inversion_count(0, v.size() - 1, v) << '\n';

    return 0;
}
