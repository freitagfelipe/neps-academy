#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, flipped;
    
    cin >> s;

    for (char ch : s) {
        if (ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '7') {
            cout << "Nao\n";

            return 0;
        }

        char new_ch {ch};

        if (ch == '6') {
            new_ch = '9';
        } else if (ch == '9') {
            new_ch = '6';
        }

        flipped.push_back(new_ch);
    }

    reverse(flipped.begin(), flipped.end());

    s == flipped ? cout << "Sim\n" : cout << "Nao\n";

    return 0;
}
