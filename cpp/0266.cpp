#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;

    cin >> n;

    int last {n.back() - '0'};

    last % 2 == 0 ? cout << "S\n" : cout << "N\n";

    long long int sum {};

    for (char ch : n) {
        int v {ch - '0'};

        sum += v;
    }

    sum % 3 == 0 ? cout << "S\n" : cout << "N\n";
    last % 5 == 0 ? cout << "S\n" : cout << "N\n";

    return 0;
}