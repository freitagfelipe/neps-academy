#include <bits/stdc++.h>
#include <numeric>

using namespace std;

typedef pair<int, string> pis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    int t {1};

    while (cin >> n && n != 0) {
        cout << "Teste " << t++ << '\n';

        vector<pis> table(n);

        for (int i {}; i < n; ++i) {
            cin >> table[i].second;

            vector<int> v(12);

            for (int &x : v) {
                cin >> x;
            }

            sort(v.begin(), v.end());

            int calc {};

            for (int i {1}; i < (int) v.size() - 1; ++i) {
                calc += v[i];
            }

            table[i].first = calc;
        }

        sort(table.begin(), table.end(), [](const pis &a, const pis &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        });

        int last_c {1}, last_score {-1}, rc {1};

        for (auto &[p, s] : table) {
            cout << (last_score != p ? rc : last_c) << " " << p << " " << s << '\n';

            if (last_score != p) {
                last_c = rc;
                last_score = p;
            }

            ++rc;
        }

        cout << '\n';
    }

    return 0;
}
