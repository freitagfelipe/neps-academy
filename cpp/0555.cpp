#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    if (n == 0) {
        cout << "E\n";
    } else if (n <= 35) {
        cout << "D\n";
    } else if (n <= 60) {
        cout << "C\n";
    } else if (n <= 85) {
        cout << "B\n";
    } else {
        cout << "A\n";
    }

    return 0;
}