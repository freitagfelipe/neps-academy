#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;

    getline(cin, str);

    int h {}, s {};

    for (int i {2}; i < str.size(); ++i) {
        if (str[i] == ')' && str[i - 1] == '-' && str[i - 2] == ':') {
            ++h;
        } else if (str[i] == '(' && str[i - 1] == '-' && str[i - 2] == ':') {
            ++s;
        }
    }

    if (s == 0 && h == 0) {
        cout << "none\n";
    } else if (s == h) {
        cout << "unsure\n";
    } else if (s > h) {
        cout << "sad\n";
    } else {
        cout << "happy\n";
    }

    return 0;
}