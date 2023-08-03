#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int z {};

    for (int x : v) {
        while (x % 2 == 0) {
            x /= 2;
            ++z;
        }
    }

    cout << (z >= k) << '\n';

    return 0;
}