#include <bits/stdc++.h>

using namespace std;
    
int occurr[10];

int main() {
    int n;

    cin >> n;

    while (n--) {
        string s;

        cin >> s;

        for (char ch : s) {
            ++occurr[ch - '0'];
        }
    }

    for (int i {}; i < 10; ++i) {
        cout << i << " - " << occurr[i] << '\n';
    }

    return 0;
}