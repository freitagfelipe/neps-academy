#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << "[";

    int c {};

    for (int i {}; i < n; ++i) {
        string a, b;

        cin >> a >> b;

        if (c++ > 0) {
            cout << ", ";
        }

        cout << "('" << a << "', '" << b << "')";
    }

    cout << "]\n";

    return 0;
}