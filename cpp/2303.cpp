#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c;

    cin >> a >> b >> c;

    if (a + b == c) {
        cout << "correct!\n";
    } else {
        cout << "wrong!\n";
    }

    return 0;
}