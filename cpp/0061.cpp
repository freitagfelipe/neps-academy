#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solver(string &s) {
    string result {};

    for (int i {0}; i < s.size(); ++i) {
        string::iterator it {upper_bound(result.begin(), result.end(), s[i])};

        if (it == result.end()) {
            result.push_back(s[i]);
        } else {
            *it = s[i];
        }
    }

    return result.size();
}

int main() {
    string s;

    cin >> s;

    cout << solver(s) << '\n';

    return 0;
}