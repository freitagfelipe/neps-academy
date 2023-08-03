#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, s, t;

    cin >> p >> s >> t;

    cout << min({s * 2 + t * 4, p * 2 + t * 2, s * 2 + p * 4}) << '\n';

    return 0;
}