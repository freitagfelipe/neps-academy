#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D() {
        this->x = 0;
        this->y = 0;
    }

	bool operator>(const Point2D &t) const {
		if (this->x == t.x) {
			return this->y > t.y;
		}

		return this->x > t.x;
	}

	bool operator<(const Point2D &t) const {
		if (this->x == t.x) {
			return this->y < t.y;
		}

		return this->x < t.x;
	}
};

template <typename T>
double distance_between_points(const Point2D<T> &a, const Point2D<T> &b) {
	T dx {a.x - b.x};
	T dy {a.y - b.y};

	return sqrt(dx * dx + dy * dy);
}

template <typename T>
double find_minimum_distance(vector<Point2D<T>> points) {
	sort(points.begin(), points.end());

	int first_active_point {};
	set<pii> active_points;

	double answer {distance_between_points(points[0], points[1])};

	for (int i {}; i < points.size(); ++i) {
		while (points[i].x - points[first_active_point].x > answer) {
			active_points.erase({points[first_active_point].y, first_active_point});

			++first_active_point;
		}

		pii search_point {points[i].y - floor(answer), 0};
		set<pii>::iterator it {active_points.lower_bound(search_point)};

		while (it != active_points.end() && it->first <= points[i].y + floor(answer)) {
			answer = min(answer, distance_between_points(points[i], points[it->second]));

			++it;
		}

		active_points.insert({points[i].y, i});
	}

	return answer;
}

int main() {
    int n;

    cin >> n;

    vector<Point2D<ll>> points(n);

    for (auto &[x, y] : points) {
        cin >> x >> y;
    }

    cout << fixed << setprecision(6) << find_minimum_distance(points) << '\n';

    return 0;
}
