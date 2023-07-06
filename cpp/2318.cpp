#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;

    cin >> x >> y;

    if (x < -8 || x > 8 || y > 8 || y < 0) {
        cout << "N\n";
    } else {
        cout << "S\n";
    }

    return 0;
}