#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll ax, ay, bx, by;

    cin >> ax >> ay >> bx >> by;

    if (ax * by - ay * bx == 0) {
        cout << 1;
    } else if (ax * bx + ay * by == 0) {
        cout << -1;
    } else {
        cout << 0;
    }

    cout << '\n';

    return 0;
}
