#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

tuple<int, int, int, int> v[MAXN];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        get<3>(v[i]) = i + 1;
    }

    for (int i {}; i < m; ++i) {
        int o, p, b;

        cin >> o >> p >> b;

        --get<0>(v[o - 1]); 
        --get<1>(v[p - 1]);
        --get<2>(v[b - 1]);
    }

    sort(v, v + n);

    for (int i {}; i < n; ++i) {
        cout << get<3>(v[i]) << " \n"[i + 1 == n];
    }

    return 0;
}