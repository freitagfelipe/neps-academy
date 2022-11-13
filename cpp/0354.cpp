#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 100000

vector<int> v[MAXN + 1];
bool DP_AUX[MAXN + 1];
int DP[MAXN + 1];

bool DFS() {
    stack<int> s;

    s.push(0);

    while (s.size() != 0) {
        int i {s.top()};

        if (v[i].size() == 0) {
            DP_AUX[i] = true;

            s.pop();

            continue;
        } else if (DP_AUX[i]) {
            DP[i] = v[i].size();

            for (int j {}; j < v[i].size(); ++j) {
                if (DP[v[i][j]] != DP[v[i][0]]) {
                    return false;
                }

                DP[i] += DP[v[i][j]];
            }

            s.pop();

            continue;
        }

        for (int j {}; j < v[i].size(); ++j) {
            if (!DP_AUX[v[i][j]]) {
                DP_AUX[i] = true;

                s.push(v[i][j]);
            }
        }
    }

    return true;
}

int main() {
    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        int x, y;

        cin >> x >> y;

        v[y].push_back(x);
    }

    if (DFS()) {
        cout << "bem\n";
    } else {
        cout << "mal\n";
    }

    return 0;
}

