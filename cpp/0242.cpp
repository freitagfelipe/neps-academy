#include <iostream>

using namespace std;

void title(string &s) {
    s[0] = toupper(s[0]);

    for (int i {1}; i < s.size(); ++i) {
        if (s[i - 1] != ' ') {
            s[i] = tolower(s[i]);
        } else {
            s[i] = toupper(s[i]);
        }
    }
}

int main() {
    string s;

    getline(cin, s);

    title(s);

    cout << s << '\n';

    return 0;
}
