#include <bits/stdc++.h>

using namespace std;

bool can_make(int k, const vector<int> &coins, int qtd = 0) {
    if (qtd >= 10 || k < 0) {
        return false;
    }

    if (k == 0) {
        return true;
    }

    for (int coin : coins) {
        if (can_make(k - coin, coins, qtd + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> coins(n);

    for (int &coin : coins) {
        cin >> coin;
    }

    can_make(k, coins) ? cout << "S\n" : cout << "N\n";

    return 0;
}