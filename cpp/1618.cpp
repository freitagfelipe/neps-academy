#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D() {
        this->x = 0;
        this->y = 0;
    }
};

template <typename T>
T dot(const Point2D<T> &a, const Point2D<T> &b) {
	return a.x * b.x + a.y * b.y;
}

template <typename T>
T cross(const Point2D<T> &a, const Point2D<T> &b) {
	return a.x * b.y - a.y * b.x;
}

template <typename T>
int region_value(const Point2D<T> &a) {
	if (a.y > 0 || (a.y == 0 && a.x > 0)) {
		return 0;
	}

	return 1;
}

template <typename T>
bool cmp(const Point2D<T> &a, const Point2D<T> &b) {
	if (region_value(a) != region_value(b)) {
		return region_value(a) < region_value(b);
	}

	if (cross(a, b) != 0) {
		return cross(a, b) > 0;
	}

	return dot(a, a) < dot(b, b);
}

int main() {
    int n;

    cin >> n;

    vector<Point2D<long long>> points(n);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    sort(points.begin(), points.end(), cmp<long long>);

    for (auto [x, y] : points) {
        cout << x << " " << y << '\n';
    }

    return 0;
}