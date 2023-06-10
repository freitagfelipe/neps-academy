#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D() = default;

    Point2D(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

template <typename T>
Point2D<double> rotate_point(const Point2D<T> &p, double theta) {
	auto [x, y] = p;

	double new_x {x * cos(theta) - y * sin(theta)};
	double new_y {x * sin(theta) + y * cos(theta)};

	return Point2D<double>(new_x, new_y);
}

int main() {
    long long x, y;
    long double angle;

    cin >> x >> y >> angle;

    Point2D<long long> original(x, y);
    Point2D<double> rotated {rotate_point(original, angle)};

    cout << fixed << setprecision(6) << rotated.x << " " << rotated.y << '\n';

    return 0;
}