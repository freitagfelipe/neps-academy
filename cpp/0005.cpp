#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, p, f, d;

    cin >> h >> p >> f >> d;

    bool ok {true};

    while (true) {
        if (f == p || f == h) {
            ok = f == h;

            break;
        }

        f += d;

        if (d == 1 && f > 15) {
            f = 0;
        } else if (f < 0) {
            f = 15;
        }
    }

    ok ? cout << "S\n" : cout << "N\n";

    return 0;
}