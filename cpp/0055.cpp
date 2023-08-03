#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c, d, e, f, g;

    cin >> n >> a >> b >> c >> d >> e >> f >> g;

    a + b + c - n + g - d - e - f != 0 ? cout << "S\n" : cout << "N\n";

    return 0;
}