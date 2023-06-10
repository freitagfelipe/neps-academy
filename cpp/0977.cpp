#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;

    getline(cin, str);

    int h {}, s {};

    for (int i {2}; i < (int) str.size(); ++i) {
        if (str[i] == ')' && str[i - 1] == '-' && str[i - 2] == ':') {
            ++h;
        } else if (str[i] == '(' && str[i - 1] == '-' && str[i - 2] == ':') {
            ++s;
        }
    }

    if (s == h) {
        cout << "neutro\n";
    } else if (s > h) {
        cout << "chateado\n";
    } else {
        cout << "divertido\n";
    }

    return 0;
}