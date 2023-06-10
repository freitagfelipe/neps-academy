#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    double sum {};

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        sum += x;
    }

    cout << fixed << setprecision(2) << sum / n << '\n';

    return 0;
}