#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cin.ignore();

    string s;

    getline(cin, s);

    for (int i {}; i < n; ++i) {
        cout << s << '\n';
    }

    return 0;
}