#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int c, b, b2, m, l;

    cin >> c >> b >> b2 >> m >> l;

    cout << c * 300 + 1500 * b + 600 * b2 + m * 1000 + l * 150 + 225 << '\n';

    return 0;
}