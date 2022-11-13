#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

pair<int, int> solver(vector<int> &a, vector<int> &b) {
    vector<vector<int>> answer(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i {}; i < a.size(); ++i) {
        for (int j {}; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                answer[i + 1][j + 1] = answer[i][j] + 1;
            } else {
                answer[i + 1][j + 1] = max(answer[i + 1][j], answer[i][j + 1]);
            }
        }
    }

    int lcs {answer[a.size()][b.size()]};

    return {abs(int(a.size()) - lcs), abs(int(b.size()) - lcs)};
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> v1(n), v2(m);

    for (int i {}; i < n; ++i) {
        cin >> v1[i];
    }

    for (int i {}; i < m; ++i) {
        cin >> v2[i];
    }

    pair<int, int> answer {solver(v1, v2)};

    cout << answer.first << " " << answer.second << '\n';

    return 0;
}