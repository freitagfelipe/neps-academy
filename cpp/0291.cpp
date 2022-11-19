#include <iostream>

using namespace std;

#define MAXF 50
#define MAXN 200
#define MAXC 1000

int w[MAXF + 1];
int v[MAXF + 1];
int DP[MAXF + 1][MAXC + 1];

int main() {
    int c, f, ct {1};

    while (cin >> c >> f && c != 0 && f != 0) {
        for (int i {1}; i <= f; ++i) {
            cin >> w[i] >> v[i];
        }

        for (int i {1}; i <= f; ++i) {
            for (int j {}; j <= c; ++j) {
                if (w[i] > j) {
                    DP[i][j] = DP[i - 1][j];
                } else {
                    DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
                }
            }
        }

        int answer {};

        for (int i {}; i <= c; ++i) {
            answer = max(answer, DP[f][i]);
        }

        cout << "Teste " << ct++ << '\n' << answer << "\n\n";
    }

    return 0;
}
