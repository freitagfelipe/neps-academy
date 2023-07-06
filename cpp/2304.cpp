#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    string day, month;

    day += s[0];
    day += s[1];

    month += s[3];
    month += s[4];

    int day_num {stoi(day)}, month_num {stoi(month)};

    if (day_num > 12) {
        cout << "EU\n";
    } else if (month_num > 12) {
        cout << "US\n";
    } else {
        cout << "either\n";
    }

    return 0;
}