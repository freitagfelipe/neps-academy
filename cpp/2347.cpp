#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    long long sum {};

    for (int &x : v) {
        cin >> x;

        sum += x;
    }

    set<int> ans;

    for (int x : v) {
        ans.insert(sum - x);
    }

    int c {};

    cout << ans.size() << '\n';

    for (int x : ans) {
        if (c++ > 0) {
            cout << " ";
        }

        cout << x;
    }

    cout << "\n";

    return 0;
}