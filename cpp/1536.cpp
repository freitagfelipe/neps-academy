#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    if (n <= 1979) {
        cout << "Geracao X!!!\n";
    } else if (n <= 1995) {
        cout << "Geracao Millennials. Muito cringe!!!\n";
    } else if (n <= 2010) {
        cout << "Geracao Z!!!\n";
    } else {
        cout << "Geracao Alpha!!!\n";
    }

    return 0;
}