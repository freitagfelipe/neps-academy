#include <iostream>
#include <queue>

using namespace std;

#define MAXN 110

int n;
int curr_dir {1};
int layer;
char mat[MAXN][MAXN];

void next_move(int j, queue<int> &q) {
    if (j + curr_dir < 0 || j + curr_dir >= n) {
        curr_dir *= -1;
        ++layer;
    } else {
        j += curr_dir;
    }

    if (layer >= n) {
        return;
    }
    
    q.push(j);
}

int bfs() {
    queue<int> q;

    q.push(0);

    int ans {}, curr_score {};

    while (!q.empty()) {
        int cj {q.front()};

        q.pop();

        if (mat[layer][cj] == 'o') {
            ++curr_score;
        } else if (mat[layer][cj] == 'A') {
            ans = max(ans, curr_score);

            curr_score = 0;
        }

        next_move(cj, q);
    }

    return max(curr_score, ans);
}

int main() {
    cin >> n;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << bfs() << '\n';

    return 0;
}
