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
void monotone_chain(set<Point2D<T>> &points, bool include_collinear = false) {
	vector<Point2D<T>> up, down;

    Point2D<T> p1 {*points.begin()}, p2 {*(--points.end())};

    up.push_back(p1);
    down.push_back(p1);

    points.erase(points.begin());

    int i {};

    for (const Point2D<T> &p : points) {
        if (i == points.size() - 1 || clockwise(p1, p, p2, include_collinear)) {
            while (up.size() >= 2 
                && !clockwise(up[up.size() - 2], up[up.size() - 1], p, include_collinear)
            ) {
                up.pop_back();
            }

            up.push_back(p);
        }

        if (i == points.size() - 1 || counterclockwise(p1, p, p2, include_collinear)) {
            while (down.size() >= 2
                && !counterclockwise(down[down.size() - 2], down[down.size() - 1], p, include_collinear)
            ) {
                down.pop_back();
            }

            down.push_back(p);
        }

        ++i;
    }

    for (int i {}; i < up.size(); ++i) {
        points.erase(up[i]);
    }

    for (int i {1}; i < down.size() - 1; ++i) {
        points.erase(down[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n && n != 0) {
        set<Point2D<int>> points;

        for (int i {}; i < n; ++i) {
            int x, y;

            cin >> x >> y;

            points.emplace(x, y);
        }

        int ans {};

        while (points.size()) {
            monotone_chain(points, true);

            ++ans;
        }

        if (ans & 1) {
            cout << "Take this onion to the lab!\n";
        } else {
            cout << "Do not take this onion to the lab!\n";
        }
    }

    return 0;
}