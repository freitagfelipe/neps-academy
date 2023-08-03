#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
    int x1;
    int y1;
    int x2;
    int y2;

    int width() {
        return abs(x1 - x2);
    }

    int height() {
        return abs(y1 - y2);
    }

    friend istream &operator>>(istream &is, Rectangle &r) {
        is >> r.x1 >> r.y1 >> r.x2 >> r.y2;

        return is;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Rectangle r1, r2;

    cin >> r1 >> r2;

    if (
        r1.x1 + r1.width() >= r2.x1 &&
        r1.x1 <= r2.x1 + r2.width() &&
        r1.y1 + r1.height() >= r2.y1 &&
        r1.y1 <= r2.y1 + r2.height()
    ) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}