#include <iostream>

using namespace std;

#define MAXN int(1e5) + 10

typedef long long ll;

struct Point2D {
    ll x;
    ll y;
};

int n;
Point2D polygon[MAXN];

ll calculate_area() {
    ll ans {};

    polygon[n] = polygon[0];

    for (int i {}; i < n; ++i) {
        ll sum_y {polygon[i + 1].y + polygon[i].y};
        ll diff_x {polygon[i + 1].x - polygon[i].x};

        ans += sum_y * diff_x;
    }

    return abs(ans / 2);
}

int main() {
    cin >> n;

    for (int i {}; i < n; ++i) {
        int x, y;

        cin >> x >> y;

        polygon[i] = {x, y};
    }

    cout << calculate_area() << '\n';

    return 0;
}
