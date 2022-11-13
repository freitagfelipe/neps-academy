#include <iostream>

using namespace std;

int main() {
    int coins[] {1, 5, 10, 25, 50, 100}, answer {}, n, current_coin {5};

    cin >> n;

    while (n != 0) {
        if (n < coins[current_coin]) {
            --current_coin;

            continue;
        }

        ++answer;

        n -= coins[current_coin];
    }

    cout << answer << '\n';

    return 0;
}