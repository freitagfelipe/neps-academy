#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<pair<int, string>> players;

    for (int i {}; i < n; ++i) {
        int h;
        string name;

        cin >> name >> h;

        players.push_back({-h, name});
    }

    sort(players.begin(), players.end());

    vector<string> times[m];

    for (int i {}; i < n; ++i) {
        times[i % m].push_back(players[i].second);
    }

    for (int i {}; i < m; ++i) {
        cout << "Time " << i + 1 << '\n';

        sort(times[i].begin(), times[i].end());

        for (int j {}; j < times[i].size(); ++j) {
            cout << times[i][j] << '\n';
        }

        cout << '\n';
    }

    return 0;
}