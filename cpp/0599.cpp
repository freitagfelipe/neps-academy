#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1000
#define MAXS 28

string dict[MAXN + 1];
int tab[MAXS][MAXS];

bool edit_distance(string &a, string &b) {
    for (int i {}; i < a.size(); ++i) {
        for (int j {}; j < b.size(); ++j) {
            int cost {};

            if (a[i] != b[j]) {
                cost = 1;
            }

            tab[i + 1][j + 1] = min({tab[i][j] + cost, tab[i + 1][j] + 1, tab[i][j + 1] + 1});
        }
    }

    return tab[a.size()][b.size()] < 3;
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        cin >> dict[i];
    }

    for (int i {}; i < MAXS; ++i) {
        tab[i][0] = i;
    }

    for (int i {}; i < MAXS; ++i) {
        tab[0][i] = i;
    }

    for (int i {}; i < m; ++i) {
        string w;

        cin >> w;

        int count {};

        for (int j {}; j < n; ++j) {
            if (edit_distance(dict[j], w)) {
                if (count++ > 0) {
                    cout << " ";
                }

                cout << dict[j];
            }
        }

        cout << '\n';
    }

    return 0;
}
