#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int last {}, streak {}, ans {};

    for (int i {}; i < n; ++i) {
        int v;

        cin >> v;

        if (v != last) {
            last = v;

            ans = max(ans, streak);

            streak = 1;
        } else {
            ++streak;
        }
    }

    ans = max(ans, streak);

    cout << ans << '\n';

    return 0;
}
