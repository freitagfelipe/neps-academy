#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> us;

    for (int i {}; i < 10; ++i) {
        int x;

        cin >> x;

        us.insert(x);
    }

    int n;

    cin >> n;

    us.find(n) != us.end() ? cout << "SIM\n" : cout << "NAO\n";

    return 0;
}