#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end(), [=](int a, int b) {
        if (a % m == b % m) {
            return a / m > b / m;
        }

        return a % m > b % m;
    });

    int c {};

    for (int x : v) {
        cout << x << " \n"[++c == (int) v.size()];
    }

    return 0;
}
