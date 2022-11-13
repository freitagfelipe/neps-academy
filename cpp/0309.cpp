#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

vector<int> g[MAX + 1];
int groups[MAX + 1];

void BFS(int x) {
    queue<int> q;

    q.push(x);

    groups[x] = x;

    while (!q.empty()) {
        int current {q.front()};
        
        q.pop();

        for (int i {}; i < g[current].size(); ++i) {
            int neighbor {g[current][i]};

            if (groups[neighbor] == 0) {
                groups[neighbor] = groups[current];

                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, q;

    cin >> n >> q;

    for (int i {}; i < q; ++i) {
        int x, y;

        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int answer {};

    for (int i {1}; i <= n; ++i) {
        if (groups[i] == 0) {
            ++answer;

            BFS(i);
        }
    }

    cout << answer << '\n';

    return 0;
}