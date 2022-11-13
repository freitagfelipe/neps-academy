#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1001

typedef long long ll;

int a[MAXN];
int DP[MAXN];

ll f(int k, int n, int m) {
    if (DP[k] != -1) {
        return DP[k];
    }

    ll result {};

    for (int i {1}; i <= n; ++i) {
        result += (a[i] * f(k - i, n, m)) % m;
    }

    return DP[k] = result % m;
}

int main() {
    int n, k, m;

    memset(DP, -1, sizeof(DP));

    cin >> n >> k >> m;

    for (int i {1}; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i {1}; i <= n; ++i) {
        cin >> DP[i];
    }

    cout << f(k, n, m) << '\n';

    return 0;
}