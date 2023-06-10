#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    unordered_map<string, priority_queue<int>> mp;

    for (int i {}; i < n; ++i) {
        string s;
        int h;

        cin >> s >> h;

        if (mp[s].size() < k) {
            mp[s].push(h);

            continue;
        }

        while (mp[s].size() >= k && mp[s].top() < h) {
            mp[s].pop();
        }

        if (mp[s].size() < k) {
            mp[s].push(h);
        }
    }

    ll ans {};

    for (auto &[_, pq] : mp) {
        while (!pq.empty()) {
            ans += pq.top();

            pq.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}