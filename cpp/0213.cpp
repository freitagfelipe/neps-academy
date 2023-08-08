#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;

    cin >> a >> b;

    if (a <= b) {
        cout << "Pedro\n";
    } else {
        cout << "Paulo\n";
    }

    return 0;
}