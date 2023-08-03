#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(4);

    for (int &x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    cout << abs((v[0] + v[3]) - (v[1] + v[2])) << '\n';

    return 0;
}