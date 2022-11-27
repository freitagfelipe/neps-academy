#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 60

int dist[MAXN];

void bfs(vector<int> g[], int s, int p) {
    memset(dist, -1, sizeof(dist));

    vector<int> ans;    
    queue<int> q;

    q.push(s);

    dist[s] = 0;

    while (!q.empty()) {
        int curr {q.front()};

        q.pop();

        int curr_dist {dist[curr] + 1};

        if (curr_dist > p) {
            continue;
        }

        for (int n : g[curr]) {
            if (dist[n] == -1 || curr_dist < dist[n]) {
                q.push(n);

                dist[n] = curr_dist;

                ans.push_back(n);                
            }
        }
    }

    sort(ans.begin(), ans.end());

    int count {};

    for (int i : ans) {
        if (count++ > 0) {
            cout << " ";
        }
        cout << i;
    }

    cout << '\n';
}

int main() {
    int C, E, L, P, i {};

    while (cin >> C >> E >> L >> P && C != 0) {
        cout << "Teste " << ++i << '\n';

        int answer {};

        vector<int> g[C + 1];

        for (int i {}; i < E; ++i) {
            int x, y;

            cin >> x >> y;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        bfs(g, L, P);
    }

    return 0;
}
