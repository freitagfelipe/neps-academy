#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    unordered_set<char> us;
    
    for (char ch : s) {
        us.insert(ch);
    }

    us.size() >= 3 ? cout << "Yes\n" : cout << "No\n";

    return 0;
}