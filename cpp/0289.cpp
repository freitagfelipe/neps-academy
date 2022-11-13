#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> v[n + 1];

    for (int i {}; i < m; ++i) {
        int t, a, b;

        cin >> t >> a >> b;

        if (t == 0) {
            bool bridge {};

            for (int j {}; j < v[a].size(); ++j) {
                if (v[a][j] == b) {
                    bridge = true;

                    break;
                }
            }

            cout << bridge << '\n';
        } else {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    return 0;
}