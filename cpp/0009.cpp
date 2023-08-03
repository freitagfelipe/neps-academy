#include <bits/stdc++.h>

using namespace std;

template<typename T>
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

    bool operator==(const Point2D &t) const {
        return this->x == t.x && this->y == t.y;
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
double length(const Point2D<T> &a) {
	return sqrt(dot(a, a));
}

template <typename T>
T squared_dist(const Point2D<T> &a, const Point2D<T> &b) {
    T x_diff {a.x - b.x}, y_diff {a.y - b.y};

    return x_diff * x_diff + y_diff * y_diff;
}

template <typename T>
Point2D<double> mid_point(const Point2D<T> &a, const Point2D<T> &b) {
    return {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
}

template <typename T>
int orientation(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c) {
    T result {a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)};

    if (result < 0) {
        return -1;
    } else if (result > 0) {
        return 1;
    }

    return 0;
}

template <typename T>
bool intersect(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, const Point2D<T> &d) {
    if (orientation(c, a, d) == 0 && orientation(c, b, d) == 0) {
        return false;
    }

    bool first_condition(orientation(a, b, c) != orientation(a, b, d));
    bool second_condition(orientation(c, d, a) != orientation(c, d, b));

    return first_condition && second_condition;
}

template <typename T>
bool r1(const vector<Point2D<T>> &points) {
    return squared_dist(points[0], points[1]) + squared_dist(points[0], points[2]) > squared_dist(points[2], points[1]);
}

template <typename T>
bool r2(const vector<Point2D<T>> &points) {
    return squared_dist(points[0], points[1]) == squared_dist(points[0], points[2]);
}

template <typename T>
bool r3(const vector<Point2D<T>> &points) {
    return orientation(points[1], points[2], points[3]) == 0 && orientation(points[1], points[3], points[4]) == 0;
}

template <typename T>
bool r4(const vector<Point2D<T>> &points) {
    return mid_point(points[1], points[2]) == mid_point(points[3], points[4]);
}

template <typename T>
bool r5(const vector<Point2D<T>> &points) {
    return squared_dist(points[1], points[2]) > squared_dist(points[3], points[4]);
}

template <typename T>
bool r6(const vector<Point2D<T>> &points) {
    Point2D<T> a {points[3] - points[5]}, b {points[4] - points[6]}, c {points[1] - points[2]};

    return dot(a, c) == 0 && dot(b, c) == 0;
}

template <typename T>
bool r7(const vector<Point2D<T>> &points) {
    return squared_dist(points[3], points[5]) == squared_dist(points[4], points[6]);
}

template <typename T>
bool r8(const vector<Point2D<T>> &points) {
    return intersect(points[0], points[5], points[1], points[2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Point2D<int>> points(7);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    if (
        r1(points) &&
        r2(points) &&
        r3(points) &&
        r4(points) &&
        r5(points) &&
        r6(points) &&
        r7(points) &&
        r8(points)
    ) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}