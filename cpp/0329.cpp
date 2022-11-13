#include <iostream>
#include <vector>

using namespace std;

vector<char> neighbors(vector<vector<char>> &v, pair<int, int> &p) {
    auto [i, j] = p;

    return {v[i + 1][j], v[i][j - 1], v[i][j + 1], v[i - 1][j]};
} 

int main() {
    int l, c;

    cin >> l >> c;

    vector<vector<char>> v(l + 2, vector<char>(c + 2, '.'));
    vector<pair<int, int>> earth;

    for (int i {1}; i <= l; ++i) {
        for (int j {1}; j <= c; ++j) {
            cin >> v[i][j];

            if (v[i][j] == '#') {
                earth.push_back({i, j});
            }
        }
    }

    int answer {};

    for (pair<int, int> &p : earth) {
        vector<char> earth_neighbors {neighbors(v, p)};

        for (char ch : earth_neighbors) {
            if (ch == '.') {
                ++answer;

                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}