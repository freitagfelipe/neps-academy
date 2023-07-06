#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int &x : a) {
        cin >> x;
    }

    for (int &x : b) {
        cin >> x;
    }

    int pa {}, pb {};

    while (pa < n && pb < m) {
        if (a[pa] == b[pb]) {
            ++pb;
        }

        ++pa;
    }

    pb == m ? cout << "S\n" : cout << "N\n";

    return 0;
}