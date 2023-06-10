#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string instruction;

    while (cin >> s && s != "99999") {
        int sum {s[0] - '0' + s[1] - '0'};

        if (sum != 0 && sum % 2 == 0) {
            instruction = "right";
        } else if (sum % 2 != 0) {
            instruction = "left";
        }

        cout << instruction << " " << s[2] << s[3] << s[4] << '\n'; 
    }

    return 0;
}