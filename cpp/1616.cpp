#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
struct Point2D {
    T x;
    T y;
    
    Point2D(T x, T y) {
	    this->x = x;
	    this->y = y;
    }
    
    Point2D& operator-=(const Point2D &t) {
        this->x -= t.x;
        this->y -= t.y;
        
        return *this;
    }
    
    Point2D operator-(const Point2D &t) const {
        return Point2D(*this) -= t;
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
double distance_between_points(const Point2D<T> &a, const Point2D<T> &b) {
	T dx {a.x - b.x};
	T dy {a.y - b.y};

	return sqrt(dx * dx + dy * dy);
}

template <typename T>
double distance_between_line_and_point(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &p) {
	Point2D<T> ab {b - a}, ap {p - a};

	T distance {abs(cross(ap, ab))};

	return distance / distance_between_points(a, b);
}

template <typename T>
double distance_between_segment_and_point(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &p) {
	if (dot(p - a, b - a) < 0) {
		return distance_between_points(p, a);
	} else if (dot(p - b, a - b) < 0) {
		return distance_between_points(p, b);
	}

	return distance_between_line_and_point(a, b, p);
}

int main() {
    int x, y;

    cin >> x >> y;

    Point2D<long long> p1(x, y);

    cin >> x >> y;

    Point2D<long long> p2(x, y);

    cin >> x >> y;

    Point2D<long long> p3(x, y);

    cout << distance_between_segment_and_point(p1, p2, p3) << '\n';

    return 0;
}