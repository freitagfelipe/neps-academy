#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c, d;

    cin >> a >> b >> c >> d;

    ll mmc {b * d / gcd(b, d)};
    
    ll up {(mmc / b) * a + (mmc / d) * c};

    cout << up / gcd(up, mmc) << " " << mmc / gcd(up, mmc) << '\n';

    return 0;
}