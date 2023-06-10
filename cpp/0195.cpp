#include <bits/stdc++.h>

using namespace std;

void print_bits(int n) {
    if (n == 0) {
        return;
    }

    print_bits(n >> 1);

    cout << (n & 1);
}

int main() {
    int n;

    cin >> n;

    if (n == 0) {
        cout << "0\n";

        return 0;
    }

    print_bits(n);

    cout << '\n';

    return 0;
}