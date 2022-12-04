#include <iostream>

using namespace std;

int main() {
    int max;

    cin >> max;

    int p, q;
    char op;

    cin >> p >> op >> q;

    if ((op == '+' && p + q <= max) || (p * q <= max)) {
        cout << "OK\n";
    } else {
        cout << "OVERFLOW\n";
    }

    return 0;
}
