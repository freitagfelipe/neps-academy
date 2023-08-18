#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    int max_v {};
    
    for (int &x : v) {
        cin >> x;

        max_v = max(max_v, x);
    }

    int sum {};

    for (int x : v) {
        if (x == max_v) {
            cout << sum << '\n';

            sum = 0;

            continue;
        }

        sum += x;
    }

    cout << sum << '\n';

    return 0;
}
