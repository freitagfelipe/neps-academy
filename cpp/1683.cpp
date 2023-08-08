#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v {
        "roraima",
        "acre",
        "amapa",
        "amazonas",
        "para",
        "rondonia",
        "tocantins"
    };

    string s;

    getline(cin, s);

    if (find(v.begin(), v.end(), s) != v.end()) {
        cout << "Regiao Norte\n";
    } else {
        cout << "Outra regiao\n";
    }

    return 0;
}