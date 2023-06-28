#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << max(x1, x2) - min(x1, x2) + max(y1, y2) - min(y1, y2) << '\n';

    return 0;
}