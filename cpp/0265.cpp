#include <iostream>
#include <queue>

using namespace std;

#define MAXN 1001

typedef pair<int, int> pii;

int p[MAXN];

int main() {
    int n, l;

    cin >> n >> l;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i {1}; i <= n; ++i) {
        pq.push({0, i});
    }

    for (int i {}; i < l; ++i) {
        int time;

        cin >> time;

        auto [ct, num] = pq.top();

        pq.pop();

        ++p[num];

        pq.push({ct + time, num});
    }

    for (int i {1}; i <= n; ++i) {
        cout << i << " " << p[i] << '\n';
    }

    return 0;
}