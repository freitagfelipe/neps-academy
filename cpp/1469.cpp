#include <iostream>

using namespace std;

#define MAXN int(1e6)

int v[MAXN];

int main() {
    int n, x;

    cin >> n;

    int maxn {};

    for (int i {}; i < n; ++i) {
        cin >> v[i];

        maxn = max(maxn, v[i]);
    }

    cin >> x;

    int needed {};

    for (int i {}; i < n; ++i) {
        needed += maxn - v[i];
    }

    if (needed == x || (needed < x && (x - needed) % n == 0)) {
        cout << "Boa Sorte\n";
    } else {
        cout << "Sem Sorte\n";
    }

    return 0;
}
