#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;

    cin >> x >> y;

    if (x < 0 || y < 0 || x > 432 || y > 468) {
        cout << "fora\n";
    } else {
        cout << "dentro\n";
    }

    return 0;
}