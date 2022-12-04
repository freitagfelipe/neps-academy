#include <iostream>
#include <iomanip>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

vector<int> g[10010];
pair<int, int> generations[10010];
bitset<10010> attended;

void bfs() {
    queue<pair<int, int>> q;

    q.push({0, 0});

    int maxg {};

    while (!q.empty()) {
        auto [c, d] = q.front();

        q.pop();

        for (int n : g[c]) {
            q.push({n, d + 1});

            maxg = max(maxg, d + 1);

            ++generations[d + 1].first;

            if (attended[n]) {
                ++generations[d + 1].second;
            }
        }
    }

    int count {};

    for (int i {1}; i <= maxg; ++i) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << fixed << setprecision(2) << 100 * generations[i].second / double(generations[i].first);
    }

    cout << '\n';
}

int main() {
    int n, c;

    cin >> n >> c;

    for (int i {1}; i <= n; ++i) {
        int f;

        cin >> f;

        g[f].push_back(i);
    }

    for (int i {}; i < c; ++i) {
        int x;

        cin >> x;

        attended[x] = true;
    }

    bfs();

    return 0;
}
