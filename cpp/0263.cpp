#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    if (s.size() < 2) {
        int n {stoi(s)};

        n % 4 == 0 ? cout << "S\n" : cout << "N\n";
        n % 9 == 0 ? cout << "S\n" : cout << "N\n";
        n % 25 == 0 ? cout << "S\n" : cout << "N\n";

        return 0;
    }

    long long int sum {};
    int last_two_v {(s[s.size() - 2] - '0') * 10 + s.back() - '0'};

    for (int i {}; i < (int) s.size(); ++i) {
        sum += s[i] - '0';
    }

    last_two_v % 4 == 0 ? cout << "S\n" : cout << "N\n";
    sum % 9 == 0 ? cout << "S\n" : cout << "N\n";
    last_two_v % 25 == 0 ? cout << "S\n" : cout << "N\n";

    return 0;
}