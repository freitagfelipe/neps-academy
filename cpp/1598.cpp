#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int na, nb;
    map<int, int> freq_a, freq_b;

    cin >> na >> nb;

    for (int i {}; i < na; ++i) {
        int x;

        cin >> x;

        freq_a[x] = 1;
    }

    for (int i {}; i < nb; ++i) {
        int x;

        cin >> x;

        freq_b[x] = 1;
    }

    int count {};

    for (auto [x, f] : freq_a) {
        if (freq_b[x] == 1) {
            ++count;
            cout << x << '\n';
        }
    }

    if (count == 0) {
        cout << "*\n";
    }

    return 0;
}
