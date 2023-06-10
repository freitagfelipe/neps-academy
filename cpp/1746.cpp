#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;

    cin >> n;

    vector<pii> events;

    for (int i {}; i < n; ++i) {
        int s, d;

        cin >> s >> d;

        events.emplace_back(0, s);
        events.emplace_back(1, s + d);
    }
    
    sort(events.begin(), events.end(), [](const pii &a, const pii &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }

        return a.second < b.second;
    });

    int count {};
    int ans {};

    for (auto [t, w] : events) {
        if (t == 0) {
            ++count;
        } else {
            --count;
        }

        ans = max(ans, count);
    }

    cout << ans << '\n';

    return 0;
}