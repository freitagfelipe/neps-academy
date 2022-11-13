#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;

    cin >> n;

    cin.get();

    stack<char> s;

    bool well_defined {true};

    for (int i {}; i < n; ++i) {
        string str;

        getline(cin, str);

        for (char ch : str) {
            if (ch == '{') {
                s.push(ch);
            } else if (ch == '}') {
                if (s.empty()) {
                    well_defined = false;

                    break;
                }

                s.pop();
            }
        }
    }

    if (well_defined && s.empty()) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}