#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    unordered_map<int, int> num_to_idx;
    vector<pii> v;

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        if (num_to_idx.count(x) == 0) {
            num_to_idx[x] = v.size();

            v.emplace_back(0, x);
        }
        
        ++v[num_to_idx[x]].first;
    }

    sort(v.begin(), v.end());

    cout << v[0].second << '\n';

    return 0;
}
