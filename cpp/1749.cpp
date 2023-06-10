#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    stack<int> s;

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        if (x == 0) {
            s.pop();
        } else {
            s.push(x);
        }
    }

    long long int ans {};

    while (!s.empty()) {
        ans += s.top();

        s.pop();
    }

    cout << ans << '\n';

    return 0;
}