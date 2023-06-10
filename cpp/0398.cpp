#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    char t;

    cin >> s >> t;

    int ans {};

    for (char ch : s) {
        if (ch == t) {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}