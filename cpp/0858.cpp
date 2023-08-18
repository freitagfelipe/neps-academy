#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    vector<int> v;

    while (cin >> n) {
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int sz {(int) v.size()};

    cout << "Apesar de muitas moedinhas o maior produto encontrado foi " << v[sz - 1] * v[sz - 2] << '\n';

    return 0;
}
