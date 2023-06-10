#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

template <typename T>
T cross(const Point2D<T> &a, const Point2D<T> &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    Point2D<int> p1(x1, y2), p2(x2, y2);

    int cross_r {cross(p1, p2)};

    if (cross_r == 0) {
        cout << "Produto vetorial paralelo\n";
    } else if (cross_r < 0) {
        cout << "Angulo menor que 180 graus\n";
    } else {
        cout << "Angulo maior que 180 graus\n";
    }

    return 0;
}