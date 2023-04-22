#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D() {
        this->x = 0;
        this->y = 0;
    }

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

    bool operator<(const Point2D &t) const {
        if (this->x == t.x) {
            return this->y < t.y;
        }

        return this->x < t.x;
    }
};

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
bool clockwise(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, bool include_collinear) {
    int result {orientation(a, b, c)};

    return result < 0 || (include_collinear && result == 0);
}

template <typename T>
bool counterclockwise(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, bool include_collinear) {
    int result {orientation(a, b, c)};

	return result > 0 || (include_collinear && result == 0);
}

template <typename T>
vector<Point2D<T>> monotone_chain(vector<Point2D<T>> &points, bool include_collinear = false) {
	sort(points.begin(), points.end());

	vector<Point2D<T>> up, down;

    up.push_back(points[0]);
    down.push_back(points[0]);

    for (int i {1}; i < points.size(); ++i) {
        if (i == points.size() - 1 || clockwise(points.front(), points[i], points.back(), include_collinear)) {
            while (up.size() >= 2 
                && !clockwise(up[up.size() - 2], up[up.size() - 1], points[i], include_collinear)
            ) {
                up.pop_back();
            }

            up.push_back(points[i]);
        }

        if (i == points.size() - 1 || counterclockwise(points.front(), points[i], points.back(), include_collinear)) {
            while (down.size() >= 2
                && !counterclockwise(down[down.size() - 2], down[down.size() - 1], points[i], include_collinear)
            ) {
                down.pop_back();
            }

            down.push_back(points[i]);
        }
    }

	vector<Point2D<T>> convex_hull {move(up)};

	for (int i {int(down.size() - 2)}; i > 0; --i) {
		convex_hull.push_back(down[i]);
	}

	return convex_hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<Point2D<ll>> points(n);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    vector<Point2D<ll>> convex_hull {monotone_chain(points)};

    cout << convex_hull.size() << '\n';

    for (int i {int(convex_hull.size() - 1)}; i >= 0; --i) {
        cout << convex_hull[i].x << " " << convex_hull[i].y << '\n';
    }

    return 0;
}