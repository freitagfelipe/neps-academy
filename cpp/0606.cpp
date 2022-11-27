#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 2010
#define INF  100000

vector<int> g[MAXN];
map<string, vector<string>> parser;
int dist[MAXN];

int bfs(int s, int e) {
    queue<int> q;

    q.push(s);

    dist[s] = 0;

    while (!q.empty()) {
        int curr {q.front()};

        q.pop();

        int curr_dist {dist[curr] + 1};

        for (int n : g[curr]) {
            if (curr_dist < dist[n]) {
                q.push(n);

                dist[n] = curr_dist;
            }
        }
    }

    return dist[e];
}

int main() {
    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        string x, y;

        cin >> x >> y;

        parser[x].push_back(y);
        parser[y];
    }

    int i {};

    for (auto it {parser.begin()}; it != parser.end(); ++it, ++i) {
        for (string &n : it->second) {
            g[i].push_back(distance(parser.begin(), parser.find(n)));
        }

        if (i == 0) {
            g[i].push_back(i + 1);
        } else if (i == n * 2 - 1) {
            g[i].push_back(i - 1);
        } else {
            g[i].push_back(i - 1);
            g[i].push_back(i + 1);
        }
        

        dist[i] = INF;
    }

    string s, e;

    cin >> s >> e;

    int s_i {int(distance(parser.begin(), parser.find(s)))};
    int e_i {int(distance(parser.begin(), parser.find(e)))};

    cout << bfs(s_i, e_i) << '\n';

    return 0;
}
