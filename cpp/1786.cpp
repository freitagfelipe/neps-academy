#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    for (int i {}; i < n; ++i) {
        if (s[i] == 'j' && n - i >= 3 && s[i + 1] == 'o' && s[i + 2] == 'i') {
            cout << "JOI";

            i += 2;
        } else {
            cout << s[i];
        }
    }

    cout << '\n';

    return 0;
}