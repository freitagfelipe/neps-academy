#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solver(int n, int k, int c = 0) {
    if (n - c * k < 1) {
        return 1;
    }

    return (n - c * k) * solver(n, k, c + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> q;

    while (q--) {
        string s;

        cin >> s;

        int n {stoi(s.substr(0, s.find('!')))}, k {s.find('!') == string::npos ? 0 : int(s.size() - s.find('!'))};

        cout << solver(n, k) << '\n';
    }

    return 0;
}