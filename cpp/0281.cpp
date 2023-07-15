#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, n;

    cin >> w >> n;

    vector<pair<int, int>> v(n);

    for (auto &[wi, pi] : v) {
        cin >> wi >> pi;
    }

    vector<int> DP(w + 1);

    for (auto [wi, pi] : v) {
        for (int cw {w}; cw >= wi; --cw) {
            if (DP[cw - wi] + pi > DP[cw]) {
                DP[cw] = DP[cw - wi] + pi;
            }
        }
    }

    cout << DP.back() << '\n';

    return 0;
}