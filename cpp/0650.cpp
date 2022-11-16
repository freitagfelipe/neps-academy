#include <iostream>
#include <climits>

using namespace std;

#define MAXN 10000

pair<int, int> v[MAXN + 1];
int DP[MAXN + 1], opt[MAXN + 1];

int main() {
    int n, tn {1};

    while (cin >> n && n != 0) {
        for (int i {}; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }

        DP[0] = v[0].first - v[0].second;
        opt[0] = 0;

        for (int i {1}; i < n; ++i) {
            int score {v[i].first - v[i].second};

            if (score > score + DP[i - 1]) {
                opt[i] = i;
            } else {
                opt[i] = opt[i - 1];
            }

            DP[i] = max(score, score + DP[i - 1]);
        }

        int answer {DP[0]}, opt_i {};

        for (int i {1}; i < n; ++i) {
            if (answer <= DP[i]) {
                opt_i = i;
                answer = DP[i];
            }
        }

        cout << "Teste " << tn++ << '\n';

        if (answer <= 0) {
            cout << "nenhum\n\n";
        } else {
            cout << opt[opt_i] + 1 << " " << opt_i + 1 << "\n\n";
        }
    }

    return 0;
}
