#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    vector<char> v, c;

    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            v.push_back(ch);
        } else {
            c.push_back(ch);
        }
    }

    cout << "Vogais: ";

    for (char ch : v) {
        cout << ch;
    }

    cout << "\nConsoantes: ";

    for (char ch : c) {
        cout << ch;
    }

    cout << '\n';

    return 0;
}