#include <iostream>

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
T cross(const Point2D<T> &a, const Point2D<T> &b) {
	return a.x * b.y - a.y * b.x;
}

template <typename T>
bool clockwise(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c) {
	return cross((b - a), (c - a)) < 0;
}

template <typename T>
bool intersect(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, const Point2D<T> &d) {
	bool first_condition {clockwise(a, b, c) != clockwise(a, b, d)};
	bool second_condition {clockwise(c, d, a) != clockwise(c, d, b)};

	return (first_condition && second_condition);
}

int main() {
    int x, y;

    cin >> x >> y;

    Point2D<long long> p1(x, y);

    cin >> x >> y;

    Point2D<long long> p2(x, y);

    cin >> x >> y;

    Point2D<long long> p3(x, y);

    cin >> x >> y;

    Point2D<long long> p4(x, y);

    cout << intersect(p1, p2, p3, p4) << '\n';

    return 0;
}