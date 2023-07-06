#include <bits/stdc++.h>

using namespace std;

#define INF LONG_LONG_MAX

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;

    cin >> n >> m >> p;

    map<string, priority_queue<ll, vector<ll>, greater<ll>>> mp;

    for (int i {}; i < n; ++i) {
        string s;

        cin >> s;

        for (int j {}; j < m; ++j) {
            int aux;

            cin >> aux;

            mp[s].push(aux);
        }
    }

    int count {};

    while (true) {
        ll minv {INF};
        string st;

        for (auto &[s, pq] : mp) {
            if (pq.size() > 0 && pq.top() < minv) {
                st = s;
                minv = pq.top();
            }
        }

        if (minv == INF) {
            break;
        }

        mp[st].pop();

        if (mp[st].size() == 0) {
            if (count++ > 0) {
                cout << " ";
            }

            cout << st;
        }

        for (auto &[s, pq] : mp) {
            if (s != st && pq.size() > 0) {
                ll val {pq.top()};

                pq.pop();

                pq.push(val + p);
            }
        }
    }

    cout << '\n';

    return 0;
}