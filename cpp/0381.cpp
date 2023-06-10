#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 3010

template <typename T>
struct Point2D {
    T x;
    T y;
    T pontuation;

    Point2D() = default;

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

    T cross_result {cross(a, b)};

	if (cross_result != 0) {
		return cross_result > 0;
	}

	return dot(a, a) < dot(b, b);
}

Point2D<ll> points[MAXN], centralized_points[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].pontuation;
    }

    ll ans {LONG_LONG_MIN};

    for (int i {}; i < n; ++i) {
        int centralized_size {};

        for (int j {}; j < n; ++j) {
            if (j == i) {
                continue;
            }
            
            centralized_points[centralized_size++] = points[j] - points[i];

            if (region_value(centralized_points[centralized_size - 1])) {
                --centralized_size;
            }
        }

        sort(centralized_points, centralized_points + centralized_size, cmp<ll>);

        for (int j {}; j < centralized_size; ++j) {
            ll current_sum {points[i].pontuation};
            int p1 {j};

            while (p1 < centralized_size && cross(centralized_points[j], centralized_points[p1]) == 0) {
                current_sum += centralized_points[p1].pontuation;

                ans = max(ans, current_sum);

                ++p1;
            }

            j = p1 - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}