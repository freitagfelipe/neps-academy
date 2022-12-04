#include <iostream>

using namespace std;

int main() {
    int af, df, as, ds;

    cin >> af >> df >> as >> ds;

    if (af != ds && as == df) {
        cout << 1;
    } else if (as != df && af == ds) {
        cout << 2;
    } else {
        cout << -1;
    }

    cout << '\n';

    return 0;
}
