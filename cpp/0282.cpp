#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin >> n;

    if (n < 4) {
        cout << "N\n";

        return 0;
    }

    for (ll i {2}; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << "S\n";

            return 0;
        }
    }

    cout << "N\n";

    return 0;
}