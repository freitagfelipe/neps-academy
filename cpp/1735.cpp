#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        string s;

        cin >> s;

        char curr {s[0]};
        int occurrences {1};

        for (int i {1}; i <= (int) s.size(); ++i) {
            if ((i != (int) s.size() && s[i] != curr) || i == (int) s.size()) {
                cout << occurrences << " " << curr;

                if (i != (int) s.size()) {
                    cout << " ";
                }

                curr = s[i];
                occurrences = 0;
            }

            ++occurrences;
        }

        cout << '\n';
    }

    return 0;
}