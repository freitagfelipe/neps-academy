#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN int(1e5 + 10)

int a[MAXN];
int b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> a[i];
    }

    for (int i {}; i < n; ++i) {
        cin >> b[i];
    }

    ll won {}, lose {};

    for (int i {}; i < n; ++i) {
        if (a[i] - b[i] > 0) {
            won += a[i] - b[i];
        } else if (b[i] - a[i] > 0) {
            lose += b[i] - a[i];
        }
    }

    cout << won << ' ' << lose << '\n';

    return 0;
}