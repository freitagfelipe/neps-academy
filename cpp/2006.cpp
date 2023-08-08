#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;

    cin >> x >> y >> z;

    if (x + y <= z) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}