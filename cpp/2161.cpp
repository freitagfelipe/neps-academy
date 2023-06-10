#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    string s;

    cin >> n >> x >> y >> s;

    for (char ch : s) {
        if (ch == 'C') {
            --x;
        } else if (ch == 'B') {
            ++x;
        } else if (ch == 'D') {
            ++y;
        } else {
            --y;
        }
    }

    cout << x << " " << y << '\n';

    return 0;
}