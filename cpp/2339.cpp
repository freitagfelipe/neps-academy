#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    s.substr(s.size() - 3) == "eh?" ? cout << "Canadian!\n" : cout << "Imposter!\n";

    return 0;
}