#include <iostream>

using namespace std;

typedef long long ll;

ll fast_multiplication(ll x, ll y, ll m) {
    if (x == 0) {
        return 0;
    }

    ll answer {fast_multiplication(x / 2, y, m)};

    answer = (2 * answer) % m;

    if (x % 2 == 0) {
        return answer;
    }

    return (answer + y) % m;
}

int main() {
    ll x, y, m;

    cin >> x >> y >> m;

    cout << fast_multiplication(x, y, m) << '\n';

    return 0;
}
