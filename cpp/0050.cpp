#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if (b != c || b + c != d || b + c + d != a) {
        cout << "N\n";
    } else {
        cout << "S\n";
    }

    return 0;
}
