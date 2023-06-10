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

    Point2D &operator-=(const Point2D &t) {
        this->x -= t.x;
        this->y -= t.y;
        
        return *this;
    }

    Point2D operator-(const Point2D &t) const {
        return Point2D(*this) -= t;
    }
};

template <typename T>
T cross(const Point2D<T> &a, const Point2D<T> &b) {
	return a.x * b.y - a.y * b.x;
}

template <typename T>
T triangle_area(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c) {
	return abs(cross(b - a, c - a)) / 2;
}

int main() {
    Point2D<int> a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    cout << triangle_area(a, b, c) << '\n';

    return 0;
}