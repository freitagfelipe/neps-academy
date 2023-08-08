#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    unordered_map<string, string> ump;

    for (int i {}; i < n; ++i) {
        string in, p;

        cin >> in >> p;

        ump[in] = p;
    }

    string s;

    int c {};

    while (cin >> s) {
        if (c++ > 0) {
            cout << " ";
        }

        cout << ump[s];
    }

    cout << '\n';

    return 0;
}