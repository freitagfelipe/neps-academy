#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        stack<char> s;
        string a;

        cin >> a;

        bool well_defined {true};

        for (char ch : a) {
            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else if (s.empty()) {
                well_defined = false;

                break;
            } else if (s.empty() || (ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{')) {
                s.pop();
            } else {
                well_defined = false;

                break;
            }
        }

        if (well_defined && s.empty()) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }

    }

    return 0;
}