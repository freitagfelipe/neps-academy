#include <iostream>

using namespace std;

#define MOD(x) x % (int(1e9) + 7)
#define MAXN 1001

typedef long long ll;

int k;
ll DP[MAXN][MAXN + 1];

ll solver(int i, int cb) {
    if (i == 0) {
        return 1;
    }

    if (DP[i][cb] != 0) {
        return MOD(DP[i][cb]);
    }

    if (cb == 1) {
        return DP[i][cb] = MOD(solver(i - 1, k));
    }

    return DP[i][cb] = MOD(solver(i - 1, k) + solver(i - 1, cb - 1));
}

int main() {
    int n;

    cin >> n >> k;

    cout << MOD(solver(n, k)) << '\n';

    return 0;
}
