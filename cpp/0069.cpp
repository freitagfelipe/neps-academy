#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x1, y1, x2, y2;

    cin >> n >> x1 >> y1 >> x2 >> y2;

    int mid {n / 2};

    if (x1 > x2) {
        swap(x1, x2);
    }

    if (y1 > y2) {
        swap(y1, y2);
    }

    if ((mid >= x1 && mid < x2) || (mid >= y1 && mid < y2)) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}