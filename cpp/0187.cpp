#include <iostream>

using namespace std;

int v[10];

int main() {
    for (int i {}; i < 10; ++i) {
        cin >> v[i];
    }

    for (int i {9}; i >= 0; --i) {
        cout << v[i] << '\n';
    }

    return 0;
}
