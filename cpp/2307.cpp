#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_length {};
    
    cin >> n;

    vector<string> v(n);

    for (string &s : v) {
        cin >> s;

        max_length = max(max_length, (int) s.size());
    }

    for (int i {}; i < max_length; ++i) {
        int sum {};
        int count {};

        for (string &s : v) {
            if (i < (int) s.size()) {
                sum += s[i];
                ++count;
            }
        }

        cout << char(sum / count);
    }

    cout << '\n';

    return 0;
}