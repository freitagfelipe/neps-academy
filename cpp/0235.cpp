#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    for (char ch : s) {
        if ('0' <= ch && ch <= '9' || ch == '-') {
            cout << ch;
        } else if (ch <= 'C') {
            cout << 2;
        } else if (ch <= 'F') {
            cout << 3;
        } else if (ch <= 'I') {
            cout << 4;
        } else if (ch <= 'L') {
            cout << 5;
        } else if (ch <= 'O') {
            cout << 6;
        } else if (ch <= 'S') {
            cout << 7;
        } else if (ch <= 'V') {
            cout << 8;
        } else if (ch <= 'Z') {
            cout << 9;
        }
    }

    cout << '\n';

    return 0;
}