#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    cout << max(a + b, a - b) << '\n' << min(a + b, a - b) << '\n';

    return 0;
}