#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e3 + 10)

int v[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    
    while (cin >> n >> m >> k && n != 0) {
        for (int i {}; i < n; ++i) {
            cin >> v[i];
        }
        
        cout << v[(--k - m % n + n) % n] << '\n';
    }

    return 0;
}
