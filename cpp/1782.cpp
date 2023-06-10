#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    string s;

    cin >> n >> a >> b >> s;

    --a;
    --b;

    for (int i {}; i < a; ++i) {
        cout << s[i];
    }

    for (int i {b}; i >= a; --i) {
        cout << s[i];
    }

    for (int i {b + 1}; i < n; ++i) {
        cout << s[i];
    }

    cout << '\n';

    return 0;
}