#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 202
#define INF 99999

int m[MAX][MAX];
bool not_visited[MAX][MAX];

vector<pair<int, int>> get_neighbors(int i, int j) {
    return {{i, j - 1}, {i, j + 1}, {i + 1, j}, {i - 1, j}};
}

int BFS(int rx, int rj) {
    queue<pair<int, int>> q;

    int group_size {};

    q.push({rx, rj});

    while (!q.empty()) {
        auto [cx, cy] = q.front();

        q.pop();

        if (!not_visited[cx][cy]) {
            continue;
        }

        ++group_size;

        vector<pair<int, int>> neighbors {get_neighbors(cx, cy)};

        for (int i {}; i < neighbors.size(); ++i) {
            auto [ni, nj] = neighbors[i];

            if (not_visited[ni][nj] && m[ni][nj] == m[cx][cy]) {
                q.push(neighbors[i]);
            }
        }

        not_visited[cx][cy] = false;
    }

    return group_size;
}

int main() {
    int l, c;

    cin >> l >> c;

    for (int i {1}; i <= l; ++i) {
        for (int j {1}; j <= c; ++j) {
            cin >> m[i][j];

            not_visited[i][j] = true;
        }
    }

    int lowest_group {INF};

    for (int i {1}; i <= l; ++i) {
        for (int j {1}; j <= c; ++j) {
            if (not_visited[i][j]) {
                int result {BFS(i, j)};
                
                if (result < lowest_group) {
                    lowest_group = result;
                }
            }
        }
    }
    
    cout << lowest_group << '\n';

    return 0;
}