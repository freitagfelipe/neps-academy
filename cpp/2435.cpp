#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n >> s;

    s += "?";

    char current_ch {s[0]};
    int cnt {}, c {};

    for (char ch : s) {
        if (current_ch != ch) {

            if (c++ > 0) {
                cout << " ";
            }

            cout << exchange(cnt, 1) << " " << exchange(current_ch, ch);

            continue;
        }

        ++cnt;
    }

    cout << '\n';

    return 0;
}
