#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    string tg;

    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            tg.push_back(ch);
        }
    }

    int p1 {}, p2 {(int) tg.size() - 1};

    while (p1 <= p2) {
        if (tg[p1++] != tg[p2--]) {
            cout << "N\n";

            return 0;
        }
    }

    cout << "S\n";

    return 0;
}