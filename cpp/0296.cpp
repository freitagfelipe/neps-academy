#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
#define MAXN 300
#define INF int(1e6)
 
vector<vector<pii>> g;
vector<int> dist, PSA;
bitset<MAXN> marked;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, c, k;
 
    while (cin >> n >> m >> c >> k && n != 0) {
        g.assign(n, vector<pii>());
        PSA.assign(c, 0);
        dist.assign(n, INF);
        marked.reset();
 
        for (int i {}; i < m; ++i) {
            int u, v, w;
 
            cin >> u >> v >> w;
 
            g[u].emplace_back(w, v);
            g[v].emplace_back(w, u);
        }
 
        marked[0] = true;
 
        for (int i {1}; i < c; ++i) {
            int cost {};
 
            marked[i] = true;
 
            for (auto [w, to] : g[i - 1]) {
                if (to == i) {
                    cost = w;
                    break;
                }
            }
 
            PSA[i] = PSA[i - 1] + cost;
        }
 
        priority_queue<pii, vector<pii>, greater<pii>> pq;
 
        dist[k] = 0;
 
        pq.push({0, k});
 
        while (!pq.empty()) {
            int curr {pq.top().second};
 
            pq.pop();
 
            if (marked[curr]) {
                continue;
            }
 
            marked[curr] = true;
 
            for (auto [w, to] : g[curr]) {
                if (dist[curr] + w < dist[to]) {
                    dist[to] = dist[curr] + w;
 
                    pq.push({dist[to], to});
                }
            }
        }
 
        int ans {INF};
 
        for (int i {}; i < c; ++i) {
            int cost {};
 
            if (i == 0) {
                cost += PSA.back();
            } else {
                cost += PSA.back() - PSA[i];
            }
 
            ans = min(ans, cost + dist[i]);
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}