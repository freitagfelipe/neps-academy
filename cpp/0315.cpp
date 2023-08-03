#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;

    cin >> n;

    ((n + 1) & n) == 0 && n != 0 ? cout << "S\n" : cout << "N\n";

    return 0;
}