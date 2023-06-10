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
};


ll gcd(ll a, ll b) {
    if (a == 0) {
       return b; 
    }

    return gcd(b % a, a);
}

template <typename T>
T calculate_area(const vector<Point2D<T>> &polygon) {
	T ans {};

	for (int i {}; i < polygon.size(); ++i) {
		Point2D<T> q {i ? polygon[i - 1] : polygon.back()};
		Point2D<T> p {polygon[i]};

		ans += (p.y + q.y) * (p.x - q.x);
	}

	return abs(ans / 2);
}

template <typename T>
ll calculate_lattice_points_in_edges(const vector<Point2D<T>> &polygon) {
    ll ans {};

    for (int i {}; i < polygon.size(); ++i) {
		Point2D<T> q {i ? polygon[i - 1] : polygon.back()};
		Point2D<T> p {polygon[i]};

        if (p.x == q.x) {
            ans += abs(p.y - q.y) - 1;
        } else if (p.y == q.y) {
            ans += abs(p.x - q.x) - 1;
        } else {
            ans += gcd(abs(p.x - q.x), abs(p.y - q.y)) - 1;
        }
    }

    return ans + polygon.size();
}

template <typename T>
ll calculate_lattice_points_inside_polygon(const vector<Point2D<T>> &polygon) {
    T area {calculate_area(polygon)};
    ll lattice_points_in_edge {calculate_lattice_points_in_edges(polygon)};

    return (2 * area - lattice_points_in_edge + 2) / 2; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<Point2D<long long>> polygon(n);

    for (auto &[x, y] : polygon) {
        cin >> x >> y;
    }

    cout << calculate_lattice_points_inside_polygon(polygon) << '\n';

    return 0;
}