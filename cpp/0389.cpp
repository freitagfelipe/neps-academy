#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    getline(cin, s);

    int p_c {};

    for (int i {}; i < (int) s.size(); ++i) {
        p_c += s[i] == 'p';

        if ((s[i] == 'p' && p_c > 1) || s[i] != 'p') {
            cout << s[i];

            p_c = 0;
        }
    }

    cout << "\n";

    return 0;
}