#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    cout << s.substr(0, unique(s.begin(), s.end()) - s.begin()) << '\n';

    return 0;
}