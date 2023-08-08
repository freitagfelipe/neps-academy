#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    set<string> s;

    for (int i {}; i < n; ++i) {
        string x;

        cin >> x;

        auto [_, b] = s.insert(x);

        if (!b) {
            cout << "A funcao nao eh boa.\n";

            return 0;
        }
    }

    cout << "A funcao eh boa.\n";

    return 0;
}