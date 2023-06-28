#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    long long int o {}, e {}, i {1};

    for (char ch : s) {
        int v {ch - '0'};

        if (i++ % 2 == 0) {
            e += v;
        } else {
            o += v;
        }
    }

    if (abs(e - o) % 11 == 0) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}