#include <iostream>
#include <algorithm>

using namespace std;

int v[10];

int main() {
    for (int i {}; i < 10; ++i) {
        cin >> v[i];
    }

    sort(v, v + 10);

    int count {};

    for (int i {}; i < 10; ++i) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << v[i];
    }

    cout << '\n';

    for (int i {9}; i >= 0; --i) {
        if (count++ > 10) {
            cout << " ";
        }

        cout << v[i];
    }

    cout << '\n';

    return 0;
}
