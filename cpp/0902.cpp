#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, m, p;

    cin >> n >> d >> m >> p;

    if (n * d > m * p) {
        cout << "NERF\n";
    } else {
        cout << "BUFF\n";
    }

    return 0;
}