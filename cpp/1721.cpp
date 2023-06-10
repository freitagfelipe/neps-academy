#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    int sz, ac {}, bc {};

    cin >> sz;

    cin.ignore();

    getline(cin, a);
    getline(cin, b);

    for (int i {}; i < sz; ++i) {
        if ('a' <= a[i] && a[i] <= 'z') {
            ac += (int) a[i];
        }

        if ('a' <= b[i] && b[i] <= 'z') {
            bc += (int) b[i];
        }
    }

    ac == bc ? cout << "S\n" : cout << "N\n";

    return 0;
}