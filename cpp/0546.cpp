#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 110

string v[MAXN];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    sort(v, v + n);

    cout << v[k - 1] << '\n';

    return 0;
}
