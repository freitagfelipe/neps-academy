#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int A, V;

    int test_number {1};

    while (cin >> A >> V && A > 0) {
        vector<pair<int, int>> v(A + 1, {0, 0});
        
        for (int i {}; i < V; ++i) {
            int x, y;

            cin >> x >> y;

            v[x].first = x;
            v[y].first = y;

            ++v[x].second;
            ++v[y].second;
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        });

        int greatest {v[0].second};

        int aux {};

        cout << "Teste " << test_number++ << '\n';

        for (auto &[a, b] : v) {
            if (b < greatest) {
                continue;
            }

            if (aux++ > 0) {
                cout << " ";
            }

            cout << a;
        }

        cout << "\n\n";
    }

    return 0;
}