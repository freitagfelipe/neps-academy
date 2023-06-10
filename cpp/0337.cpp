#include <bits/stdc++.h>

using namespace std;

int memo[31];

int hanoi(int n) {
    if (memo[n] != 0) {
        return memo[n];
    }

    return memo[n] = hanoi(n - 1) + hanoi(n - 1) + 1;
}

int main() {
    memo[1] = 1;

    int t {};
    int n;

    while (cin >> n && n != 0) {
        cout << "Teste " << ++t << '\n';
        cout << hanoi(n) << "\n\n";
    }

    return 0;
}