#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 1010
#define MAXR 1000000

unordered_map<int, int> DP[MAXN];
pii boxes[MAXN];

int solver(int idx, int res) {
    if (res < 0) {
        return -1;
    }

    if (idx < 0 || res == 0) {
        return 0;
    }
    
    if (DP[idx].count(res) != 0) {
        return DP[idx][res];
    }

    return DP[idx][res] = max(solver(idx - 1, min(res, boxes[idx].first) - boxes[idx].second) + 1, solver(idx - 1, res));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> boxes[i].second >> boxes[i].first;
    }

    sort(boxes, boxes + n);

    cout << solver(n - 1, MAXR) << '\n';

    return 0;
}