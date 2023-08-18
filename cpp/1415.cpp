#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int min_x {INT_MAX}, max_x {INT_MIN}, min_y {INT_MAX}, max_y {INT_MIN};

    for (int i {}; i < n; ++i) {
        int x, y;
        char ch;

        cin >> x >> ch >> y;

        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    cout << min_x - 1 << "," << min_y - 1 << '\n';
    cout << max_x + 1 << "," << max_y + 1 << '\n';

    return 0;
}
