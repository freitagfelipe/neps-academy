#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p;

    while (cin >> g >> p && g != 0 && p != 0) {
        unordered_map<int, vector<int>> stats;

        for (int i {}; i < g; ++i) {
            for (int j {}; j < p; ++j) {
                int pi;

                cin >> pi;

                stats[j].push_back(pi);
            }
        }

        int s;

        cin >> s;

        for (int i {}; i < s; ++i) {
            int k;

            cin >> k;

            vector<int> points(p, 0);

            for (int j {}; j < k; ++j) {
                cin >> points[j];
            }

            vector<pii> pnt(p);

            for (auto &[pi, stat] : stats) {
                for (int placement : stat) {
                    pnt[pi].first += points[placement - 1];
                }

                pnt[pi].second = pi;
            }

            sort(pnt.begin(), pnt.end(), [](const pii &a, const pii &b) {
                if (a.first == b.first) {
                    return a.second < b.second;
                }

                return a.first > b.first;
            });

            int winner {pnt[0].first};

            for (int i {}; i < p; ++i) {
                if (pnt[i].first == winner) {
                    cout << pnt[i].second + 1 << " \n"[i + 1 == p || pnt[i + 1].first != winner];
                }
            }
        }
    }

    return 0;
}