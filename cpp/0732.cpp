#include <bits/stdc++.h>

using namespace std;

int main() {
    int attack, defense, life, dmg;
    string s;

    cin >> s >> attack >> defense >> life >> dmg;

    if (dmg >= defense + life) {
        cout << s << " morreu :(\n";
    } else {
        cout << s << " sobreviveu!!!\n";
    }

    return 0;
}