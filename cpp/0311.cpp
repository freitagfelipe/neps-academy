#include <bits/stdc++.h>

using namespace std;

long long int count_setted_bits(long long int n) {
    if (n == 0) {
        return 0;
    }

    return (n & 1) + count_setted_bits(n >> 1);
}

int main() {
    long long int n;

    cin >> n;

    cout << count_setted_bits(n) << '\n';

    return 0;
}