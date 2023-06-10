#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "n\n";

        return 0;
    }

    if (a > c && a > b) {
        swap(a, c);
    } else if (b > c && b > a) {
        swap(b, c);
    }

    if (a * a + b * b == c * c) {
        cout << "r\n";
    } else if (a * a + b * b < c * c) {
        cout << "o\n";
    } else {
        cout << "a\n";
    }

    return 0;
}