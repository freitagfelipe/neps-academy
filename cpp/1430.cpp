#include <bits/stdc++.h>

using namespace std;

int ans {-1};

void kmp(string s) {
    int n {(int) s.size()};

    vector<int> pi(s.size());

    for (int i {1}, j {}; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            ++j;
        }

        pi[i] = j;
    }

    for (int i {}; i < n; ++i) {
        if (pi[i] != 0) {
            ans = max(ans, n - (n - i) + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    for (int i {}; i < (int) s.size(); ++i) {
        kmp(s.substr(i));
    }

    cout << ans << '\n';

    return 0;
}