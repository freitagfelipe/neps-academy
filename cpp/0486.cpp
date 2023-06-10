#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

    bool operator<(const Point2D &t) const {
		if (this->x == t.x) {
			return this->y > t.y;
		}

		return this->x < t.x;
	}
};

template <typename T>
T dot(const Point2D<T> &a, const Point2D<T> &b) {
	return a.x * b.x + a.y * b.y;
}

template <typename T>
T norm(const Point2D<T> &a) {
    return dot(a, a);
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
bool cw(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, bool include_collinear = false) {
    int result {orientation(a, b, c)};

    return result < 0 || (include_collinear && result == 0);
}

template <typename T>
bool ccw(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c, bool include_collinear = false) {
    int result {orientation(a, b, c)};

	return result > 0 || (include_collinear && result == 0);
}

template <typename T>
bool point_in_segment(const Point2D<T> &a, const Point2D<T> &b, const Point2D<T> &c) {
	if (orientation(a, b, c)) {
		return false;
	}

	if (min(a.x, b.x) > c.x || c.x > max(a.x, b.x)) {
		return false;
	} else if (min(a.y, b.y) > c.y || c.y > max(a.y, b.y)) {
		return false;
	}

	return true;
}

template <typename T>
int get_region(const vector<Point2D<T>> &points, const Point2D<T> &t, bool include_collinear = false) {
    if (!cw(points[0], points[1], t, include_collinear)) {
        return 0;
    }

    if (!cw(points.back(), points[0], t, include_collinear)) {
        return 0;
    }

	int start {1}, end {(int) points.size() - 2}, ans {1};

	while (start <= end) {
		int mid {(start + end) / 2};

		if (cw(points[0], points[mid], t, include_collinear)) {
            ans = mid;

			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return ans;
}

template <typename T>
bool inside_polygon(const vector<Point2D<T>> &points, const Point2D<T> &t, bool include_collinear = false) {
    if (points.size() < 3) {
        return point_in_segment(points[0], points[1], t);
    }

	int region {get_region(points, t, include_collinear)};

	if (region == 0) {
		return false;
	}

    if (include_collinear && point_in_segment(points[0], points[region], t)) {
        return true;
    } else if (include_collinear && point_in_segment(points[0], points[region + 1], t)) {
        return true;
    } else if (include_collinear && point_in_segment(points[region], points[region + 1], t)) {
        return true;
    }

	return cw(points[region], points[region + 1], t);
}

template <typename T>
vector<Point2D<T>> monotone_chain(vector<Point2D<T>> &points, bool include_collinear = false) {
	sort(points.begin(), points.end());

	vector<Point2D<T>> up, down;

    Point2D<T> p1 {points[0]}, p2 {points.back()};

    up.push_back(p1);
    down.push_back(p1);

    for (int i {1}; i < points.size(); ++i) {
        if (i == points.size() - 1 || cw(p1, points[i], p2, include_collinear)) {
            while (up.size() >= 2 
                && !cw(up[up.size() - 2], up.back(), points[i], include_collinear)
            ) {
                up.pop_back();
            }

            up.push_back(points[i]);
        }

        if (i == points.size() - 1 || ccw(p1, points[i], p2, include_collinear)) {
            while (down.size() >= 2
                && !ccw(down[down.size() - 2], down.back(), points[i], include_collinear)
            ) {
                down.pop_back();
            }

            down.push_back(points[i]);
        }
    }

	if (include_collinear && up.size() == points.size()) {
		reverse(up.begin(), up.end());

		return up;
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

    int n, q;

    cin >> n >> q;

    vector<Point2D<ll>> points(n), unknowns(q);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    for (auto &[x, y] : unknowns) {
        cin >> x >> y;
    }

    points = monotone_chain(points);

    int ans {};

    for (const Point2D<ll> unknown : unknowns) {
        ans += inside_polygon(points, unknown, true);
    }

    cout << ans << '\n';

    return 0;
}