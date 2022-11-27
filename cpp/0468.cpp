#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main() {
    int n, k;

    cin >> n >> k;

    unordered_map<ll, ll> freq;
    ll sum {}, ans {};

    freq[0] = 1;

    for (int i {}; i < n; ++i) {
        int v;

        cin >> v;

        sum += v;

        ans += freq[sum - k];

        ++freq[sum];
    }

    cout << ans << '\n';

    return 0;
}
