#include <iostream>
#include <map>

using namespace std;

int main() {
    int c, n;

    cin >> c >> n;

    map<int, int> m, answer;

    for (int i {}; i < c; ++i) {
        int a, b;

        cin >> a >> b;

        m[a] = b;
    }

    for (int i {}; i < n; ++i) {
        int a, b;

        cin >> a >> b;

        if (m[a] < b) {
            m[a] = b;
            answer[a] = b;
        }
    }

    for (auto [key, value] : answer) {
        cout << key << " " << value << '\n';
    }

    return 0;
}