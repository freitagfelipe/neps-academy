#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, d, b;

    cin >> p >> d >> b;

    int sum {p + d * 2 + b * 3};

    if (sum >= 150) {
        cout << "B\n";
    } else if (sum >= 120) {
        cout << "D\n";
    } else if (sum >= 100) {
        cout << "P\n";
    } else {
        cout << "N\n";
    }

    return 0;
}