#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

#define MAXN 5000

int v[] = {2, 5, 10, 20, 50, 100};
int n[6];
ll DP[6][MAXN + 1];

ll solver(int i, int s) {
    if (i == 6 || s == 0) {
        return s == 0;
    }

    if (DP[i][s] != -1) {
        return DP[i][s];
    }

    ll ans {};

    for (int j {}; j <= n[i] && j * v[i] <= s; ++j) {
        ans += solver(i + 1, s - j * v[i]);
    }

    return DP[i][s] = ans;
}

int main() {
    for (int i {}; i < 6; ++i) {
        memset(DP[i], -1, sizeof(DP[i]));
    }

    int s;

    cin >> s;

    for (int i {}; i < 6; ++i) {
        cin >> n[i];
    }

    cout << solver(0, s) << '\n';

    return 0;
}
