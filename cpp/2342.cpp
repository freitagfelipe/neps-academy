#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll d;
    string s;

    cin >> s >> d;

    ll num {};

    int idx {};

    for (char ch : s) {
        if (ch == 'B') {
            num |= (1 << idx);
        }

        ++idx;
    }

    num += d;

    for (int i {}; i < (int) s.size(); ++i) {
        cout << (num & 1 ? 'B' : 'A');

        num >>= 1;
    }

    cout << '\n';

    return 0;
}