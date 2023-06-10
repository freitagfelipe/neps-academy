#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    int p1 {-1}, p2 {(int) s.size()};

    while (++p1 <= --p2) {
        if (s[p1] != s[p2]) {
            cout << "nao eh palindromo\n";

            return 0;
        }
    }

    cout << "eh palindromo\n";

    return 0;
}