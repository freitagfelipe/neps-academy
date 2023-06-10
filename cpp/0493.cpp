#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;

    cin >> s >> t;

    for (int i {}; i < (int) t.size(); ++i) {
        cout << s[t[i] - 'a'];
    }

    cout << '\n';

    return 0;
}