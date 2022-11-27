#include <iostream>

using namespace std;

#define MAXN int(1e6)

int v[MAXN];

int main() {
    int n, d, ans {}, total_sum {};

    cin >> n >> d;

    for (int i {}; i < n; ++i) {
        cin >> v[i];

        total_sum += v[i];
    }

    int p1 {}, p2 {}, curr {v[0]};

    while (p1 < n && p2 < n) {
        if (curr == d) {
            ++ans;
        }

        if (curr < d) {
            ++p2;

            if (p2 < n) {
                curr += v[p2];
            }
        } else {
            curr -= v[p1++];
        }
    }
    
    p1 = 0, p2 = 1;

    while (p1 < n && p2 < n && p1 != p2) {
        if (total_sum == d) {
            ++ans;
        }

        if (total_sum < d) {
            total_sum += v[++p1];
        } else {
            total_sum -= v[p2++];
        }
    }

    cout << ans << '\n';

    return 0;
}
