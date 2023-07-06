#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    string s;
    int ans {-1};

    while (n--) {
        string p;
        int v;

        cin >> p >> v;

        if (v > ans) {
            ans = v;
            s = p;
        }
    }

    cout << s << '\n';
    cout << ans << '\n';

    return 0;
}