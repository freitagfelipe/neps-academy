#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, c;

    cin >> c >> n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int answer {};

    for (int i {}; i < n; ++i) {
        int t, d;

        cin >> t >> d;

        if (pq.size() < c) {
            pq.push({d + t, t});
        } else if (pq.top().first < t) {
            pq.pop();

            pq.push({d + t, t});
        } else {
            auto [et, it] = pq.top();

            pq.pop();

            if (et - t > 20) {
                ++answer;
            }

            pq.push({et + d, t});
        }
    }

    cout << answer << '\n';

    return 0;
}